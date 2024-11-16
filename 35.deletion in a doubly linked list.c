#include<stdio.h>
#include<stdlib.h>
int main(){
        struct node{
        struct node *previous;
        int data;
        struct node *next;
    };
    struct node *head=0 , *tail ,*temp ,*prev=0;
    int choice,data,i,pos;
    while(1){
        printf("Enter 1 to create a node\nEnter 2 to print normally\nEnter 3 to print reversely\nEnter 4 to delete at the beginning\nEnter 5 to delete at the end\nEnter 6 to delete at a position\n");
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
                if( head==0 ){
                    printf("Empty\n");
                }
                else{
                    temp=head;
                    head=head->next;
                    head->previous=0;
                    free(temp);
                }
                
                break;
            case 5:
                if( tail==0 ){
                    printf("Empty\n");
                }
                else{
                    temp=tail;
                    tail=tail->previous;
                    tail->next=0;
                    free(temp);
                }
                
                break;
            case 6:
                printf("Enter the position : ");
                scanf("%d",&pos);
                temp=head;
                i=1;
               if( head==0 ){
                printf("Empty\n");
               }
               else{
                while(i<pos){
                    prev=temp;
                    temp=temp->next;
                    i++;
                }
                prev->next=temp->next;
                struct node *next_pos=temp->next;
                next_pos->previous=prev;
               }
                break;
        }
    }
    
}
