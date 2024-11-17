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
    struct node *newnode , *head=0 , *tail , *temp ,*prev;
    int choice , data , i ,pos;
    while(1){
        printf("Enter 1 to create a node\nEnter 2 to display\nEnter 3 to insert at the begining\nEnter 4 to insert at the end\nEnter 5 to insert at any position\nEnter 6 to delete at the begining\nEnter 7 to delete the end\nEnter 8 to delete at any position\n");
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
            case 3:
            printf("Enter the element : ");
            scanf("%d",&data);
            newnode = creating( data );
            if( head==0 ){
                head=tail=newnode;
                head->previous=head;
                head->next=head;
            }
            else{
                newnode->previous=tail;
                newnode->next=head;
                head->previous=newnode;
                tail->next=newnode;
                head=newnode;
            }
            break;
            case 4:
            printf("Enter the element : ");
            scanf("%d",&data);
            newnode = creating( data );
            if( head==0 ){
                head=tail=newnode;
                head->previous=head;
                head->next=head;
            }
            else{
                newnode->previous=tail;
                tail->next=newnode;
                newnode->next=head;
                head->previous=newnode;
                tail=newnode;
            }
            break;
            case 5:
            printf("Enter the element : ");
            scanf("%d",&data);
            newnode = creating( data );
            printf("Enter the position : ");
            scanf("%d",&pos);
            i=1;
            temp=head;
            while( i<pos ){
                prev=temp;
                temp=temp->next;
                i++;
            }
            newnode->previous=prev;
            newnode->next=temp;
            temp->previous=newnode;
            prev->next=newnode;
            break;
            case 6:
            temp=head;
            head=head->next;
            head->previous=tail;
            tail->next=head;
            free(temp);
            break;
            case 7:
            temp=tail;
            tail=tail->previous;
            tail->next=head;
            head->previous=tail;
            free(temp);
            break;
            case 8:
            printf("Enter the position : ");
            scanf("%d",&pos);
            i=1;
            temp = head;
            while( i<pos ){
                prev=temp;
                temp=temp->next;
                i++;
            }
            struct node *next_node;
            next_node=temp->next;
            prev->next=next_node;
            next_node->previous=prev;
            free(temp);
            break;
            default:
            return 0;
        }
    }
}