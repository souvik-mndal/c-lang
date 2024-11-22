#include<bits/stdc++.h>
using namespace std;
class info{
    string name;
    int age;
    int sem;
    int roll;
    public:
    void setval( string n , int a , int s , int r ){
        name=n;
        age=a;
        sem=s;
        roll=r;
    }
    void getval(){
        cout<<name<<" "<<age<<" "<<sem<<" "<<roll<<endl;
    }
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
    i1.setval(namee,agee,semm,rolll);
    i1.getval();
}