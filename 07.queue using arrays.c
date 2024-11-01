#include<stdio.h>
#define n 5
int main(){
int choice,x;
    while( 1 ){
        printf("Enter 1 for push \nEnter 2 for pop\nEnter 3 for finding the peek element\nEnter 4 for display the stack\nEnter 5 to check full\nEnter 6to check empty\nEnter 7 to exit \n");
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
                printf("EXITED SUCCESSFULLY\n\n");
                return 0;
                break;
            default:
                printf("ENTER THE CORRECT NUMBER \n\n");
        }
    }
}