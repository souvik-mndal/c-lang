#include<stdio.h>
#include<stdlib.h>
int main(){
        struct node{
        struct node *previous;
        int data;
        struct node *next;
    };
    struct node *head=0 , *tail ,*temp;
    int choice,data;
    while(1){
        printf("Enter 1 to create a node\nEnter 2 to print normally\nEnter 3 to print reversely\nEnter 4 to insert at the beginning\nEnter 5 to insert at the end\nEnter 6 to enter at a position\n");
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
                temp=tail;
                while(temp!=0){
                    printf("%d ",temp->data);
                    temp=temp->previous;
                }
                printf("\n");
                break;
            case 4:
                printf("Enter the element : ");
                scanf("%d",&data);
                struct node *firstnode = (struct node*)malloc(sizeof(struct node));
                firstnode->data = data;
                firstnode->previous=0;
                firstnode->next=head;
                head->previous=firstnode;
                head=firstnode;
                break;
            // case 5:
                
            //     break;
            // case 6:
                
            //     break;
        }
    }
    
}
