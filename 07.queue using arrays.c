#include<stdio.h>
#define n 5
int queue[n];
int front = -1 , rear = -1 ;
void push( int x ){
    if( rear == n-1 ){
        printf("\nOVERFLOW\n");
    }
    else if( rear==-1 && front==-1){
        front++;rear++;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x ;
    }
}
void pop( ){
    if( front==-1 ){
        printf("\nUNDERFFLOW\n");
    }
    else if( front==rear ){
        front=-1;
        rear=-1;
    }
    else{
        printf("\nThe popped element is : %d \n",queue[front]);
        front++;
    }
}
void peek( ){
    if( front==-1 ){
        printf("\nQUEUE IS EMPTY\n");
    }
    else{
        printf("\nTHE PEEK ELEMENT IS : %d \n",queue[front]);
    }
}
void display(){
    if( front==-1 ){
        printf("\nQUEUE IS EMPTY\n");
    }
    else{
        for( int i=front ; i<=rear ; i++ ){
            printf("%d ",queue[i]);
        }
    }
}
void empty(){
    if( front==-1 && rear==-1 ){
        printf("\nQUEUE IS EMPTY\n");
    }
    else{
        printf("QUEUE IS NOT EMPTY ");
    }
}

int main(){
int choice,x;
    while( 1 ){
        printf("Enter 1 for push \nEnter 2 for pop\nEnter 3 for finding the peek element\nEnter 4 for display the queue\nEnter 5 to check empty\nEnter 6 to exit \n");
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
                display();
                printf("\n\n");
                break;
            case 5:
                empty();
                printf("\n\n");
                break;
            case 6:
                printf("EXITED SUCCESSFULLY\n\n");
                return 0;
                break;
            default:
                printf("ENTER THE CORRECT NUMBER \n\n");
        }
    }
}