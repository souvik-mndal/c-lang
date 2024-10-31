#include<stdio.h>
#define n 5
int stack[n];
int top=-1;
void push( int x ){
    if( top==n-1 ){
        printf("OVER FLOW\n\n");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop(){
    if( top==-1 ){
        printf("UNDER FLOW\n\n");
    }
    else{
        top--;
    }
}
void mini(){
    if(top==-1 ){
        printf("NO ELEMENT PRESENT IN  THE STACK");
        return;
    }
    int minimum=stack[0];
    for( int i=1 ; i<=top ; i++ ){
        if( stack[i]<minimum){
            minimum=stack[i];
        }
    }
    printf("THE MINIMUM ELEMENT IS : %d",minimum);
}
int main(){
    int choice , x ;
    while( 1 ){
        printf("enter 1 for push \nEnter 2 for pop\nEnter 3 for exit \n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element you want to push : ");
                scanf("%d",&x);
                push(x);
                mini();
                printf("\n\n");
                break;
            case 2:
                pop();
                mini();
                printf("\n\n");
                break;
            case 3:
                printf("EXITED SUCCESSFULLY");
                return 0;
            default:
                printf("Enter the correct number ");
        }
    }
}