import * as THREE from 'https://unpkg.com/three@0.160.0/build/three.module.js';

const container = document.getElementById('app');

const renderer = new THREE.WebGLRenderer({ antialias: true, powerPreference: 'high-performance' });
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
renderer.setSize(container.clientWidth, container.clientHeight, false);
renderer.outputColorSpace = THREE.SRGBColorSpace;
container.appendChild(renderer.domElement);

const scene = new THREE.Scene();
const camera = new THREE.OrthographicCamera(-1, 1, 1, -1, 0, 1);

const uniforms = {
  iTime: { value: 0 },
  iResolution: { value: new THREE.Vector3(container.clientWidth, container.clientHeight, 1) },
  iMouse: { value: new THREE.Vector2(0, 0) },
};

const vertexShader = /* glsl */ `
  precision highp float;
  varying vec2 vUv;
  void main() {
    vUv = uv;
    gl_Position = vec4(position.xy, 0.0, 1.0);
  }
`;

// Fragment shader renders large tapered strokes with cutout holes, matching the
// reference’s bold white-on-black calligraphic shapes.
const fragmentShader = /* glsl */ `
  precision highp float;
  uniform vec3 iResolution;
  uniform float iTime;
  uniform vec2 iMouse;
  varying vec2 vUv;

  // Signed distance to a line segment
  float sdSegment(vec2 p, vec2 a, vec2 b) {
    vec2 pa = p - a, ba = b - a;
    float h = clamp(dot(pa, ba) / dot(ba, ba), 0.0, 1.0);
    return length(pa - ba * h);
  }

  vec2 bezier(vec2 a, vec2 b, vec2 c, vec2 d, float t) {
    float u = 1.0 - t;
    float uu = u*u;
    float tt = t*t;
    return uu*u*a + 3.0*uu*t*b + 3.0*u*tt*c + tt*t*d;
  }

  // Distance to a tapered cubic Bezier stroke (polyline approximation)
  float sdBezierStroke(vec2 p, vec2 a, vec2 b, vec2 c, vec2 d, float r0, float r1) {
    const int N = 48; // segments
    float minD = 1e9;
    vec2 prev = a;
    float prevT = 0.0;
    for (int i = 1; i <= N; i++) {
      float t = float(i) / float(N);
      vec2 cur = bezier(a, b, c, d, t);
      float midT = 0.5 * (t + prevT);
      // Subtle width modulation for organic edges
      float wobble = 0.04 * sin(12.0 * midT + iTime * 0.9);
      float r = mix(r0, r1, midT) * (1.0 + wobble);
      float dseg = sdSegment(p, prev, cur) - r;
      minD = min(minD, dseg);
      prev = cur;
      prevT = t;
    }
    return minD;
  }

  // Combine SDFs: union and subtraction
  float opUnion(float a, float b) { return min(a, b); }
  float opSubtract(float a, float b) { return max(a, -b); }

  void main() {
    vec2 res = iResolution.xy;
    float aspect = res.x / res.y;
    vec2 p = vUv * 2.0 - 1.0;
    p.x *= aspect;

    float t = iTime;

    // Primary sweeping stroke (top-left to bottom-right)
    vec2 a1 = vec2(-1.35 * aspect,  0.90);
    vec2 b1 = vec2(-0.40 * aspect + 0.25*sin(t*0.6),  0.60);
    vec2 c1 = vec2( 0.55 * aspect + 0.30*cos(t*0.5), -0.40);
    vec2 d1 = vec2( 1.30 * aspect, -0.85);
    float sd = sdBezierStroke(p, a1, b1, c1, d1, 0.55, 0.06);

    // Secondary bottom-left curl
    vec2 a2 = vec2(-1.10 * aspect, -0.85);
    vec2 b2 = vec2(-0.65 * aspect, -0.55);
    vec2 c2 = vec2( 0.05 * aspect, -0.10 + 0.10*sin(t*0.7));
    vec2 d2 = vec2( 0.80 * aspect,  0.10 + 0.06*cos(t*0.6));
    sd = opUnion(sd, sdBezierStroke(p, a2, b2, c2, d2, 0.40, 0.10));

    // Right-side upward flick
    vec2 a3 = vec2( 0.25 * aspect, -0.25);
    vec2 b3 = vec2( 0.75 * aspect,  0.05);
    vec2 c3 = vec2( 0.90 * aspect,  0.50);
    vec2 d3 = vec2( 0.70 * aspect,  1.10);
    sd = opUnion(sd, sdBezierStroke(p, a3, b3, c3, d3, 0.28, 0.04));

    // Cutout holes to mimic negative spaces
    vec2 ha = vec2( 0.25 * aspect, -0.10);
    vec2 hb = vec2( 0.70 * aspect,  0.05);
    vec2 hc = vec2( 0.55 * aspect,  0.35);
    vec2 hd = vec2( 0.30 * aspect,  0.45);
    float hole1 = sdBezierStroke(p, ha, hb, hc, hd, 0.16, 0.02);
    sd = opSubtract(sd, hole1);

    vec2 ha2 = vec2(-0.80 * aspect, -0.20);
    vec2 hb2 = vec2(-0.35 * aspect, -0.05);
    vec2 hc2 = vec2( 0.10 * aspect,  0.20);
    vec2 hd2 = vec2( 0.35 * aspect,  0.35);
    float hole2 = sdBezierStroke(p, ha2, hb2, hc2, hd2, 0.20, 0.04);
    sd = opSubtract(sd, hole2);

    // Convert SDF to high-contrast color with AA
    float edge = fwidth(sd) * 1.25;
    float fill = smoothstep(0.0, edge, -sd);
    vec3 col = vec3(fill);
    gl_FragColor = vec4(col, 1.0);
  }
`;

const material = new THREE.ShaderMaterial({
  uniforms,
  vertexShader,
  fragmentShader,
});

const mesh = new THREE.Mesh(new THREE.PlaneGeometry(2, 2), material);
scene.add(mesh);

function resizeRendererToDisplaySize() {
  const width = container.clientWidth;
  const height = container.clientHeight;
  const needsResize = renderer.domElement.width !== Math.floor(width * renderer.getPixelRatio()) ||
                      renderer.domElement.height !== Math.floor(height * renderer.getPixelRatio());
  if (needsResize) {
    renderer.setSize(width, height, false);
    uniforms.iResolution.value.set(width, height, 1);
  }
}

window.addEventListener('resize', resizeRendererToDisplaySize);
window.addEventListener('pointermove', (e) => {
  const rect = renderer.domElement.getBoundingClientRect();
  uniforms.iMouse.value.set(
    (e.clientX - rect.left) / rect.width,
    1.0 - (e.clientY - rect.top) / rect.height
  );
});

let start = performance.now();
function render() {
  const now = performance.now();
  uniforms.iTime.value = (now - start) * 0.001;
  resizeRendererToDisplaySize();
  renderer.render(scene, camera);
  requestAnimationFrame(render);
}

render();

