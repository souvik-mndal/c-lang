#include<bits/stdc++.h>
using namespace std;
class parent{
    protected:
    int age,weight;
};
class child : private parent{
    int class_no;
    public:
    child(int age , int weight ,  int class_no ){
        this->age = age;
        this->weight = weight;
        this->class_no = class_no;
    }
    void display(){
        cout<<age<<" "<<weight<<" "<<class_no<<endl;
    }
};
int main(){
    child c1( 17 , 55 , 12 );
    c1.display();
}