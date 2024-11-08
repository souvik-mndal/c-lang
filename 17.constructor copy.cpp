#include<iostream>
using namespace std;
class student{
    private:
    string name;
    int age,roll;
    string grade;
    public:
    student( string name , int age , int roll , string grade ){
        this->name = name ;
        this->age = age ;
        this->roll = roll ;
        this->grade = grade ;
    }
    student( student &a ){
        name = a.name;
        age = a.age;
        roll = a.roll;
        grade = a.grade;
    }
    void display( ){
        cout<<name<<" "<<age<<" "<<roll<<" "<<grade<<endl;
    }
};
int main(){
    student s1( "SM" , 17 , 173 , "B+" );
    s1.display();
    student s2( s1 );
    s2.display();
}