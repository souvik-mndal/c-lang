#include<stdio.h>
#define n 5
int main(){
    int choice;
    while( 1 ){
        printf("Enter 1 for push \nEnter 2 for pop\nEnter 3 for finding the peek element\nEnter 4 for display the stack\nEnter 5 to exit ");
        printf("Enter what you want to choose : ");
        scanf( "%d",&choice);
        switch( choice ){
            case 1:
            int x;
            printf("Enter the element you want to push : ");
            scanf("%d",&x);
            push(x);
            break;
        }
    }
}