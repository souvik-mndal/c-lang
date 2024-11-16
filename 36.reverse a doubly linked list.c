#include<stdio.h>
#include<stdlib.h>
int main(){
        struct node{
        struct node *previous;
        int data;
        struct node *next;
    };
    struct node *head=0 , *tail ,*temp ,*prev=0;
    int choice,data;
    while(1){
        printf("Enter 1 to create a node\nEnter 2 to print normally\nEnter 3 to reverse it\n");
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
                    head=tail=newnode;
                }
                else{
                    tail->next=newnode;
                    newnode->previous=tail;
                    tail=newnode;
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
                struct node *next_node;
                while(temp!=0){
                    next_node=temp->next;
                    temp->next=temp->previous;
                    temp->previous=next_node;
                    prev=temp;
                    temp=temp->previous;
                }
                head=prev;
                break;

        }
    }
    
}
