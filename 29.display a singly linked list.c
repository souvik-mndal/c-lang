#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *creating( int n ){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if( newnode==0 ){
        printf("Falied memory allocation\n");
        exit(1);
    }
    newnode->data=n;
    newnode->next=0;
    return newnode;
}
void display( struct node *head){
    struct node *temp=head;
    while( temp!=0 ){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    struct node *head , *temp;
    head=0;
    int choice,data;
    do{
        printf("Enter the element : ");
        scanf("%d",&data);
        struct node *newnode = creating( data );
        if( head==0 ){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Enter 1 to make a node and 0 to exit : ");
        scanf("%d",&choice);
    }while(choice!=0);
    display( head );
}