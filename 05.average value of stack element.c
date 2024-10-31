#include<stdio.h>
#define n 5
int stack[5];
int top = -1 ;
void push( int x ){
    if( top==n-1 ){
        printf("OVERFLOW\n\n");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop(){
    if( top==-1 ){
        printf("UNDERFLOW");
    }
    else{
        top--;
    }
}
void average( ){
    int sum=0;
    int ele = top+1;
    for( int i=0 ; i<=top ; i++ ){
        sum+=stack[i];
    }
    printf("The average is : %f",sum/(float)ele);
}
int main(){
    int choice , value;
    while(1){
        printf("Enter 1 for push \nEnter 2 for pop \nEnter 3 for exit \n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch( choice ){
            case 1:
                printf("Enter the value : ");
                scanf("%d",&value);
                push(value);
                average();
                printf("\n\n");
                break;
            case 2 :
                pop();
                average();
                printf("\n\n");
                break;
            case 3:
                printf("EXITED SUCCESSFULLY ");
                return 0;
                break;
            default:
                printf("WRONG INPUT ");
        }
    }
}