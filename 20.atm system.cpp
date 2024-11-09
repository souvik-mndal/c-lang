#include<bits/stdc++.h>
using namespace std;
// acc_no balance name pin
// withdram transfer viewbalance exit
class atm{
    string name;
    long long int account_no;
    int balance;
    int pin;
    public:
    void withdraw(){
        int n;
        cout<<"Enter the amount you want to withdraw : ";
        cin>>n;
        balance = balance - n;
        if( balance < 0 ){
            cout<<"Insufficient balance\n ";
        }
        else{
            cout<<"Withdrawn successfully\n ";
        }
    }
    void transfer(){
        int n;
        cout<<"Enter 1 to transfer to yourself\nEnter 2 to transfer to other\n ";
        cout<<"Enter your choice : ";
        cin>>n;
        switch( n ){
            case 1 :
                balance +=n ;
                cout<<"SUCCESSFULL...\n";
                break;
            case 2:
                long long int acc;
                cout<<"Enter the account number where you want to transfer : ";
                cin>>acc;
                balance-=n;
                cout<<"TRANSFERED SUCCESSFULLY...\n";
                break;
            default:
                cout<<"WRONG KEY...\n";
        }
    }
    void viewbal(){
        cout<<"Your current balance is : "<<balance<<endl;
    }
    void key(){
        int check;
        cout<<"Enter~"
        if( check==pin ){
            int n;
            cout<<"Enter "
        }
    }
}
int main(){

}