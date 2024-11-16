#include<stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *node;
};
struct node *create_node( int n ){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if( newnode==0 ){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = n;
    newnode->node = 0;
    return newnode;
}
int main(){
    
    struct node *head , *temp;
    head=0;
    int choice , element ;
    do{
        printf("Enter the element value : ");
        scanf("%d",&element);
        struct node *newnode = create_node( element );
        if( head==0 ){
            head=temp=newnode;
        }
        else{
            temp->node = newnode;
            temp=newnode;
        }
        printf("Enter 1 to add another node and 0 to stop : ");
        scanf("%d",&choice);
    }while(choice!=0);
}