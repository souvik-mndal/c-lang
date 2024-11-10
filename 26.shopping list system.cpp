#include<bits/stdc++.h>
using namespace std;
// item_code item_price count 
// get_item display_sum remove display end
class shopping{
    vector<string>item_code;
    vector<int>item_price;
    static int balance;
    public:
    void put_items(){
        string code;
        int price;
        cout<<"Enter the item code : ";
        cin>>code;
        cout<<"Enter the price of the item : ";
        cin>>price;
        item_code.push_back(code);
        item_price.push_back(price);
        balance+=price;
    }
    static int bal(){
        return balance;
    }
    void display_sum(){
        cout<<"The total price of the items are : "<<bal()<<endl;
    }
    void remove(){
        int n=item_code.size();
        cout<<"Enter the number which item you want to delete out of "<<n<<" inputs : ";
        int value;
        cin>>value;
        balance=balance-item_price[value-1];
        item_price.erase(item_price.begin()+value-1);
    }
    void display(){
        int n=item_code.size();
        for( int i=0 ; i<n ; i++ ){
            cout<<i+1<<" "<<item_code[i]<<" "<<item_price[i]<<endl;
        }
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