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

// Fragment shader generates evolving high-contrast abstract black/white forms
const fragmentShader = /* glsl */ `
  precision highp float;
  uniform vec3 iResolution;
  uniform float iTime;
  uniform vec2 iMouse;
  varying vec2 vUv;

  // Hash, noise and fbm helpers
  float hash(vec2 p) {
    p = fract(p * vec2(123.34, 345.45));
    p += dot(p, p + 34.345);
    return fract(p.x * p.y);
  }

  float noise(vec2 p) {
    vec2 i = floor(p);
    vec2 f = fract(p);
    // Quintic curve for smooth interpolation
    vec2 u = f*f*f*(f*(f*6.0-15.0)+10.0);
    float a = hash(i + vec2(0.0, 0.0));
    float b = hash(i + vec2(1.0, 0.0));
    float c = hash(i + vec2(0.0, 1.0));
    float d = hash(i + vec2(1.0, 1.0));
    return mix(mix(a, b, u.x), mix(c, d, u.x), u.y);
  }

  float fbm(vec2 p) {
    float value = 0.0;
    float amp = 0.5;
    float freq = 1.0;
    for (int i = 0; i < 6; i++) {
      value += amp * noise(p * freq);
      p += vec2(37.0, 17.0);
      freq *= 2.0;
      amp *= 0.5;
    }
    return value;
  }

  mat2 rot(float a) {
    float s = sin(a), c = cos(a);
    return mat2(c, -s, s, c);
  }

  // Curved stripe field via domain-warped projection
  float curvedStripes(vec2 p, float t) {
    // Domain warp the coordinates by a slowly changing fbm field
    vec2 w = vec2(fbm(p * 0.7 + t * 0.05), fbm(p * 0.7 - t * 0.04));
    p += (w - 0.5) * 2.2; // warp strength
    float angle = fbm(p * 0.35 + t * 0.03) * 3.14159;
    p = rot(angle) * p;
    float stripes = 0.5 + 0.5 * sin(p.x * 7.5 + t * 1.2);
    // Convert to crisp bands
    float wline = 0.18; // band width
    float edge = fwidth(stripes) * 1.5;
    return smoothstep(0.5 - wline - edge, 0.5 - wline + edge, stripes) -
           smoothstep(0.5 + wline - edge, 0.5 + wline + edge, stripes);
  }

  // Large blobby masks
  float blobs(vec2 p, float t) {
    vec2 q = p;
    q += 0.35 * vec2(cos(t*0.2), sin(t*0.23));
    q += (fbm(p*0.8 - t*0.05) - 0.5) * 2.0;
    float v = fbm(q*1.2);
    float e = fwidth(v) * 1.5;
    return smoothstep(0.52 - e, 0.52 + e, v);
  }

  void main() {
    vec2 uv = vUv;
    // Map to centered, aspect-correct coords
    vec2 res = iResolution.xy;
    float aspect = res.x / res.y;
    vec2 p = (uv * 2.0 - 1.0);
    p.x *= aspect;

    float t = iTime;

    // Base large white regions
    float mask = blobs(p*0.8, t);

    // Flowing stripes layered on top
    float stripes = curvedStripes(p, t);

    // Combine: either large mask or stripes brighten to white
    float lum = max(mask, stripes);

    // Optional secondary thin highlights
    float highlights = curvedStripes(p * 1.65 + 2.7, t * 0.8);
    lum = max(lum, highlights * 0.9);

    // High-contrast black/white output
    vec3 col = vec3(lum > 0.5 ? 1.0 : 0.0);
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

