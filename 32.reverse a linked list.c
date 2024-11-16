#include<stdio.h>
#include<stdlib.h>
int main(){
        struct node{
        int data;
        struct node *node;
    };
    struct node *head=0 , *temp , *prev=0 ,*next;
    int choice,data;
    while(1){
        printf("Enter 1 to create a node\nEnter 2 to display\nEnter 3 to reverse\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch( choice ){
            case 1:
                printf("Enter the element : ");
                scanf("%d",&data);
                struct node *newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data = data;
                newnode->node=0;
                if( head==0){
                    head=temp=newnode;
                }
                else{
                    temp=head;
                    while( temp->node!=0 ){
                        temp = temp->node;
                    }
                    temp->node=newnode;
                    temp=newnode;
                }
                break;
            case 2:
                temp = head;
                while( temp!=0 ){
                    printf("%d ",temp->data);
                    temp=temp->node;
                }
                printf("\n");
                break;
            case 3:
                temp=head;
                while(temp!=0 ){
                    next = temp->node;
                    temp->node=prev;
                    prev=temp;
                    temp = next;
                }

                head = prev;
                break;
        }
    }
}