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
    int choice,data,i,pos;
    struct node *head=0, *temp ,*newnode ,*tail , *prev;
    while( 1 ){
        printf("Enter 1 to create a new node\nenter 2 to display\nEnter 3 to insert at the begining\nEnter 4 to insert at the end\nEnter 5 to insert at any position\nEnter 6 to delete at the begining\nEnter 7 to delete the end\nEnter 8 to delete at any position\n");
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
            case 5:
            printf("Enter the element : ");
            scanf("%d",&data);
            printf("Enter the position : ");
            scanf("%d",&pos);
            newnode=creating( data );
            temp=head;
            i=1;
            while( i<pos ){
                prev = temp;
                temp = temp->next;
                i++;
            }
            prev->next=newnode;
            newnode->next=temp;
            break;
            case 6:
            temp=head;
            head=head->next;
            tail->next=head;
            free(temp);
            break;
            case 7:
            temp=tail;
            struct node *trav=head;
            while( trav->next!=tail){
                trav=trav->next;
            }
            trav->next=head;
            tail=trav;
            free(temp);
            break;
            // case 8:
            
            // break;
            default:
            return 0;
        }
    }
    
}