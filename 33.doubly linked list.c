#include<stdio.h>
#include<stdlib.h>
int main(){
        struct node{
        struct node *previous;
        int data;
        struct node *next;
    };
    struct node *head=0 , *temp;
    int choice,data;
    while(1){
        printf("Enter 1 to create a node\nEnter 2 to print normally\nEnter 3 to print reversely\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch( choice ){
            case 1:
                printf("Enter the element : ");
                scanf("%d",&data);
                struct node *newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data = data;
                newnode->previous=0;
                newnode->next=0;
                if( head==0){
                    head=temp=newnode;
                }
                else{
                    temp->next=newnode;
                    newnode->previous=temp;
                    temp=newnode;
                }
                break;
            case 2:
                temp=head;
                while(temp!=0){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
                break;
            case 3:
                temp=head;
                while( temp->next!=0){
                    temp=temp->next;
                }
                while(temp!=0){
                    printf("%d ",temp->data);
                    temp=temp->previous;
                }
                printf("\n");
                break;
        }
    }
    
}
