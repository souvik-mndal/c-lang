#include<iostream>
using namespace std;
class student{
    public:
    string name;
    int age,roll;
    string grade;
};
int main(){
    student s1 = {"SM" , 17 , 173 , "B+"};
    cout<<s1.name<<" "<<s1.age<<" "<<s1.roll<<" "<<s1.grade;
    // s1.name = "SM";
    // s1.age = 17;
    // s1.roll = 173;
    // s1.grade = "B+";
}