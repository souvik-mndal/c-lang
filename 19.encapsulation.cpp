#include<iostream>
using namespace std;
class student{
    private:
    int age;
    public:
    student(int age ){
        if( age>100 && age<=0 ){
            cout<<"Invalid";
        }
        else{
            this->age = age;
        }
    }
    void display(){
        cout<<age<<endl;
    }
};
int main(){
    student s1(99);
    s1.display();
    student s2(109);
    s2.display();
    student s3(18);
    s3.display();
}