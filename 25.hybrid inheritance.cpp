#include<iostream>
using namespace std;
// device 
// phone camera
// smartphone
class device{
    public:
    void dev_print(){
        cout<<"i am the device class\n";
    }
};
class phone : virtual public device{
    public:
    void phone_print(){
        cout<<"i am the phone class\n";
    }
};
class camera : virtual public device{
    public:
    void camera_print(){
        cout<<"i am the camera class\n";
    }
};
class smartphone : public phone , public camera{
    public:
    void smart_print(){
        cout<<"i am the smartphone class\n";
    }
};
int main(){
    smartphone s1;
    s1.smart_print();
    s1.camera_print();
    s1.phone_print();
    s1.dev_print();
}