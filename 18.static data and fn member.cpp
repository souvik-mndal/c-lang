#include<iostream>
using namespace std;
class student{
    private:
    string name;
    int balance;
    static int customer_no;
    public:
    student( string s , int no ){
        name = s ;
        balance = no ;
        customer_no++;
    }
    static void display(){
        cout<<customer_no<<endl;
    }
};
int student::customer_no=0;
int main(){
    student s1("sm" , 1000 );
    student s2("km" , 2000 );
    student s3("bm" , 3000 );
    student::display();
}