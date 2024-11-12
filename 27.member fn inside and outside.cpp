#include<iostream>
using namespace std;
class value{
    int x;
    public:
    void setdata( int n );
    void getdata(){
        cout<<"The value is : "<<x<<endl;
    }
};
void value :: setdata( int n ){
    x = n;
}
int main(){
    value v1;
    v1.setdata( 100 );
    v1.getdata();
}