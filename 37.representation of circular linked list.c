#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *creating( int n ){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=0;
    return newnode;
}
int main(){
    int choice,data;
    struct node *head=0, *temp ,*newnode;
    while( 1 ){
        printf("Enter 1 to create a new node\nenter 2 to display\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element : ");
            scanf("%d",&data);
            newnode = creating( data );
            if( head==0 ){
                head=temp=newnode;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
            newnode->next=head;
            break;
            case 2:
            temp=head;
            while(temp->next!=head){
                printf("%d ",temp->data);
                temp=temp->next;
            }
            printf("%d\n",temp->data);
            break;
            default:
            return 0;
        }
    }
    
}