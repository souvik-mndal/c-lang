#include<stdio.h>
#include<stdlib.h>
int main(){
        struct node{
        int data;
        struct node *node;
    };
    struct node *head=0 , *temp , *prev=0;
    int choice,data,i,pos;
    while(1){
        printf("Enter 1 to create a node\nEnter 2 to insert at the start\nEnter 3 to insert at the end\nEnter 4 to insert at a position\nEnter 5 to display\n");
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
                    temp->node=newnode;
                    temp=newnode;
                }
                break;
            case 2:
                printf("Enter the element : ");
                scanf("%d",&data);
                struct node *firstnode = (struct node*)malloc(sizeof(struct node));
                firstnode->data = data;
                firstnode->node = head;
                head = firstnode;
                break;
            case 3:
                
                printf("Enter the element : ");
                scanf("%d",&data);
                struct node *lastnode = (struct node*)malloc(sizeof(struct node));
                temp=head;
                while( temp->node!=0 ){
                    temp = temp->node;
                }
                lastnode->data = data;
                lastnode->node = 0;
                temp->node = lastnode;
                break;
            case 4:
                i=1;
                printf("Enter the element : ");
                scanf("%d",&data);
                printf("Enter the position : ");
                scanf("%d",&pos);
                temp = head;
                while( i<pos){
                    prev = temp;
                    temp=temp->node;
                    i++;
                }
                struct node *midnode = (struct node*)malloc(sizeof(struct node));
                midnode->data = data;
                midnode->node=temp;
                prev->node = midnode;
                break;
            case 5:
                temp = head;
                while( temp!=0 ){
                    printf("%d ",temp->data);
                    temp=temp->node;
                }
                printf("\n");
            break;
        }
    }
    
}