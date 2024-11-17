#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *previous;
    int data;
    struct node *next;
};
struct node *creating( int n ){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->previous=0;
    newnode->next=0;
    return newnode;
}
int main(){
    struct node *newnode , *head=0 , *tail , *temp;
    int choice , data;
    while(1){
        printf("Enter 1 to create a node\nEnter 2 to display\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element : ");
            scanf("%d",&data);
            newnode = creating( data );
            if( head==0 ){
                head=tail=newnode;
                head->previous=head;
                head->next=head;
            }
            else{
                tail->next=newnode;
                newnode->previous=tail;
                newnode->next=head;
                head->previous=newnode;
                tail=newnode;
            }
            break;
            case 2:
            temp=head;
            while( temp->next!=head ){
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