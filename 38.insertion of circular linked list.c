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
    struct node *head=0, *temp ,*newnode ,*tail;
    while( 1 ){
        printf("Enter 1 to create a new node\nenter 2 to display\nEnter 3 to insert at the begining\nEnter 4 to insert at the end\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element : ");
            scanf("%d",&data);
            newnode = creating( data );
            if( head==0 ){
                head=tail=newnode;
            }
            else{
                tail->next=newnode;
                tail=newnode;
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
            case 3:
            printf("Enter the element : ");
            scanf("%d",&data);
            newnode = creating( data );
            if(head==0){
                head=tail=newnode;
                newnode->next=head;
            }
            else{
                newnode->next=head;
                head=newnode;
                tail->next=head;
            }
            
            break;
            case 4:
            printf("Enter the element : ");
            scanf("%d",&data);
            newnode=creating( data );
            if(head==0){
                head=tail=newnode;
            }
            else{
                tail->next=newnode;
                tail=newnode;
            }
            newnode->next=head;
            break;
            default:
            return 0;
        }
    }
    
}