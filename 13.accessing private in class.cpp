#include<bits/stdc++.h>
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
    void setgrade( string s ){
        grade = s;
    }
    string getname( ){
        return name;
    }
    int getage(){
        return  age;
    }
    int getroll(){
        return roll;
    }
    string getgrade(){
        return grade;
    }
};
int main(){
    student s1;
    s1.setname( "SM" );
    s1.setage( 17 );
    s1.setroll( 173 );
    s1.setgrade( "B+" );
    cout<<s1.getname()<<" "<<s1.getage()<<" "<<s1.getroll()<<" "<<s1.getgrade();
    // s1.name = "SM";
    // s1.age = 17;

    // s1.roll = 173;
    // s1.grade = "B+";
}