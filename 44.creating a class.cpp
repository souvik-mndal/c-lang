#include<bits/stdc++.h>
using namespace std;
class info{
    public:
    string name;
    int age;
    int sem;
    int roll;
};
int main(){
    info i1;
    string namee;
    int agee,semm,rolll;
    cout<<"Enter your name : ";
    getline(cin,namee);
    cout<<"Enter your age : ";
    cin>>agee;    
    cout<<"Enter your sem : ";
    cin>>semm;    
    cout<<"Enter your roll : ";
    cin>>rolll;
    i1.name=namee;
    i1.age=agee;
    i1.sem=semm;
    i1.roll=rolll;
    cout<<i1.name<<" "<<i1.age<<" "<<i1.sem<<" "<<i1.roll;    
}