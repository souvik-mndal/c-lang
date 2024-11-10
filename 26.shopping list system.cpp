#include<iostream>
using namespace std;
// item_code item_price count 
// get_item display_sum remove display end
class shopping{
    string item_code;
    int item_price;
    int count = 0;
    static int balance;
    public:
    void put_items(){
        string code;
        int price;
        cout<<"Enter the item code : ";
        cin>>code;
        cout<<"Enter the price of the item : ";
        cin>>price;
        item_code = code;
        item_price = price;
        count = count+1;
        balance+=price;
    }
    static int bal(){
        return balance;
    }
    void display_sum(){
        cout<<"The total price of the items are : "<<bal()<<endl;
    }
    void remove(){

    }
    void display(){
        cout<<count<<" "<<item_code<<" "<<item_price<<endl;
    }
};
int shopping::balance = 0;
int main(){
    shopping *s = new shopping;
    while(1){
        cout<<"Enter 1 to place the item value\nEnter 2 to display the sum of the price\nEnter 3 to remove any items \nEnter 4 to display the items\nEnter 5 to exit\n";
        int n;
        cout<<"Enter your choice : ";
        cin>>n;
        switch(n){
            case 1 :
                s->put_items();
                break;
            case 2 :
                s->display_sum();
                break;
            case 3 :
                s->remove();
                break;
            case 4 :
                s->display();
                break;
            case 5 :
                cout<<"happy to help you\n";
                break;
            default:
                cout<<"OOPS Something went wrong\n";
        }
    }
}