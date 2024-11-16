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
                firstnode->next=0;
                if(head==0 ){
                    head=firstnode;
                    tail=firstnode;
                }
                else{
                    firstnode->next=head;
                    head->previous=firstnode;
                    head=firstnode;
                }
                
                break;
            case 5:
                printf("Enter the element : ");
                scanf("%d",&data);
                struct node *endnode = (struct node*)malloc(sizeof(struct node));
                endnode->data=data;
                endnode->next=0;
                endnode->previous=0;
                if(tail==0){
                    head=endnode;
                    tail=endnode;
                }
                else{
                    endnode->previous=tail;
                    tail->next=endnode;
                    tail=endnode; 
                }
                
                break;
            case 6:
                printf("Enter the element : ");
                scanf("%d",&data);
                printf("Enter the position : ");
                scanf("%d",&pos);
                struct node *middlenode = (struct node*)malloc(sizeof(struct node));
                middlenode->data=data;
                i=1;
                temp=head;
                while( i<pos ){
                    prev=temp;
                    temp=temp->next;
                    i++;
                }
                middlenode->next=temp;
                temp->previous=middlenode;
                middlenode->previous=prev;
                prev->next=middlenode;
                break;
        }
    }
    
}
