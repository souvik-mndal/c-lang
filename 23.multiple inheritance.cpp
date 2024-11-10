#include<iostream>
using namespace std;
class football{
    public:
    void foot(){
        cout<<"i love playing football\n";
    }
};
class cricket{
    public:
    void cric(){
        cout<<"i love playing cricket\n";
    }
};
class sports : public football , public cricket{
    public:
    void sport_p(){
        cout<<"i love playing both\n";
    }
};
int main(){
    sports s1;
    s1.sport_p();
    s1.cric();
    s1.foot();
}