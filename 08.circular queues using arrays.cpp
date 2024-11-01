#include<stdio.h>
#define n 5
int queue[n];
int front=-1 , rear =-1 ;
void push( int x ){
    if( (rear+1)%n==front){
        printf("OVERFLOW");
    }
    else if( front==-1 && rear==-1 ){
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else{
        rear=(rear+1)%n;
        queue[rear]=x;
    }
}
void pop(){
    if( front==-1 && rear==-1 ){
        printf("UNDERDLOW");
    }
    else if( front==rear ){
        front=rear=-1;
    }
    else{
        printf("The popped element is : %d ",queue[front]);
        front=(front+1)%n;
    }
}
void peek( ){
    if( front==-1 && rear==-1){
        printf("EMPTY");
    }
    else{
        printf("%d ",queue[front]);
    }
}
void isfull( ){
    if( (rear+1)%n == front ){
        printf("FULL");
    }
    else{
        printf("NOT FULL ENOUGH");
    }
}
void isempty( ){
    if( front==-1 && rear==-1 ){
        printf("EMPTY");
    }
    else{
        printf("NOT EMPTY");
    }
}
void display(){
    int i=front;
    if( front==-1 && rear==-1 ){
        printf("EMPTY");
    }
    else{
        while( i!=rear ){
            printf("%d ",queue[i]);
            i = (i+1)%n;
        }
        printf("%d",queue[rear]);
    }
}
int main(){
    int choice,x;
    while( 1 ){
        printf("Enter 1 for push \nEnter 2 for pop\nEnter 3 for finding the peek element\nEnter 4 for checking isfull\nEnter 5 to check empty\nEnter 6 to display \nEnter 7 to exit\n");
        printf("Enter what you want to choose : ");
        scanf( "%d",&choice);
        switch( choice ){
            case 1:
                printf("Enter the element you want to push : ");
                scanf("%d",&x);
                push(x);
                printf("\n\n");
                break;
            case 2:
                pop();
                printf("\n\n");
                break;
            case 3:
                peek();
                printf("\n\n");
                break;
            case 4:
                isfull();
                printf("\n\n");
                break;
            case 5:
                isempty();
                printf("\n\n");
                break;
            case 6:
                display();
                printf("\n\n");
                break;
            case 7:
                printf("EXITED SUCCESSFULLY\n\n");
                return 0;
                break;
            default:
                printf("ENTER THE CORRECT NUMBER \n\n");
        }
    }
}