#include<iostream>
using namespace std;
class sports{
    public:
    void sport_print(){
        cout<<"i am the parent\n";
    }
};
class football : public sports{
    public:
    void foot_print(){
        cout<<"i am the first child named football\n";
    }
};
class kabaddi : public sports{
    public:
    void kab_print(){
        cout<<"i am the first child named kabaddi\n";
    }
};
int main(){
    football f1;
    f1.foot_print();
    f1.sport_print();
    kabaddi k1;
    k1.kab_print();
    k1.sport_print();
}