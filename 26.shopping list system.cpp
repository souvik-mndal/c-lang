#include<iostream>
using namespace std;
// item_code item_price count 
// get_item display_sum remove display end
class shopping{
    string item_code;
    int item_price;
    static int count;
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
    }
};
int shopping::count = 0;
int main(){

}