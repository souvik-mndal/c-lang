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
        cout<<"Enter the pin : ";
        cin>>check;
        int chance=0;
        while( chance>2 ){
            if( check!=pin ){
                cout<<"SORRY ! TOU HAVE ENTERED THE ERONG PIN...PLEASE TRY AGAIN\n";
            }
            else{
                cout<<"WELCOME SIR ... WHAT DO YOU WANT TO DO\n";
                while(1){
                    int no;
                    cout<<"Enter 1 for withdraw\nEnter 2 for transfer\nEnter 3 to view balance\nEnter 4 to exit\n";
                    cout<<"Enter your choice : ";
                    cin>>no;
                    switch(no){
                        case 1:
                            withdraw();
                            break;
                        case 2:
                            transfer();
                            break;
                        case 3:
                            viewbal();
                            break;
                        case 4:
                            cout<<"THANK YOU .... VISIT AGAIN \n";
                            return ;
                        default:
                            cout<<"OOPS ! SOMETHING WENT WRONG\n ";
                    }
                }
                
            }
        }
        cout<<"YOUR ACCOUNT HAS BEEN LOCKED FOR 24HRS\n";
    }
}
int main(){
    
}