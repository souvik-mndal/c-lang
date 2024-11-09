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
            cout<<"Insufficient balance ";
        }
        else{
            cout<<"Withdrawn successfully ";
        }
    }
}
int main(){

}