#include<iostream>
using namespace std;
class student{
    private:
    string name;
    int age,roll;
    string grade;
    public:
    student( string s , int a , int b , string t ){
        name = s ;
        age = a ;
        roll = b ;
        grade = t;
    }
    void display( ){
        cout<<name<<" "<<age<<" "<<roll<<" "<<grade<<endl;
    }
};
int main(){
    student s1( "SM" , 17 , 173 , "B+" );
    s1.display();
}