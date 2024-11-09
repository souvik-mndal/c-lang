#include<iostream>
using namespace std;
class student{
    private:
    int age;
    public:
    void setage(int age ){
        if( age<=100 && age>0 ){
            this->age = age;
        }
        else{
            cout<<"Invalid";
        }
    }
    void display(){
        cout<<age<<endl;
    }
};
int main(){
    student s1;
    s1.setage(99);
    s1.display();
    student s2;
    s2.setage(109);
}