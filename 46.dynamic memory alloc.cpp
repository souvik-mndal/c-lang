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
    info *i = new info;
    string namee;
    int agee,semm,rolll;
    int choice;
    while(1){
        cout<<"Enter 1 to enter the values\nEnter 2 to display the informations\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter your name : ";
                cin.ignore();
                getline(cin,namee);
                cout<<"Enter your age : ";
                cin>>agee;    
                cout<<"Enter your sem : ";
                cin>>semm;    
                cout<<"Enter your roll : ";
                cin>>rolll;
                i->setval(namee,agee,semm,rolll);
                break;
            case 2:
                i->getval();
                break;
            default:
                cout<<"wrong input\n";
                return 0;
        }
    }
}