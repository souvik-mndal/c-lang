#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    string name;
    int age,roll;
    string grade;
    
};
int main(){
    student *s = new student;
    (*s).name = "SM";
    (*s).age = 17;
    (*s).roll = 173;
    s->grade = "B+";
    cout<<s->name<<" "<<s->age<<" "<<s->roll<<" "<<s->grade;
}