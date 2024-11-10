#include<bits/stdc++.h>
using namespace std;
class grandparent{
    protected:
    int age,weight;
};
class parent : protected grandparent{
    protected:
    string gender;
};
class child : private parent{
    int class_no;
    public:
    child(int age , int weight , string gender , int class_no ){
        this->age = age;
        this->weight = weight;
        this->gender = gender;
        this->class_no = class_no;
    }
    void display(){
        cout<<age<<" "<<weight<<" "<<gender<<" "<<class_no<<endl;
    }
};
int main(){
    child c1( 17 , 55 , "male" , 12 );
    c1.display();
}