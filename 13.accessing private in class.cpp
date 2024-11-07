#include<iostream>
using namespace std;
class student{
    private:
    string name;
    int age,roll;
    string grade;
    public:
    void setname( string s ){
        name = s;
    }
    void setage( int n ){
        age = n;
    }
    void setroll( int n ){
        roll = n;
    }
    void setgrade{ string s ){
        grade = s;
    }
};
int main(){
    student s1;
    s1.setname( "SM" );
    s1.setage( 17 );
    s1.setroll( 173 );
    s1.setgrade( "B+" );
    cout<<s1.name<<" "<<s1.age<<" "<<s1.roll<<" "<<s1.grade;
    // s1.name = "SM";
    // s1.age = 17;

    // s1.roll = 173;
    // s1.grade = "B+";
}