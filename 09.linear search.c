#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of elements you want to take : ");
    scanf("%d",&n);
    int arr[n];
    for( int i=0 ; i<n ; i++ ){
        printf("Enter the element for index : %d ",i);
        scanf("%d",&arr[i]);
    }
    int x;
    printf("Enter the target element you want to find : ");
    scanf("%d",&x);
    int flag = 0 ;
    for( int i=0 ; i<n ; i++ ){
        if( arr[i]==x ){
            flag=1;
            printf("The target element is present at index : %d" , i );
        }
    }
    if( flag==0 ){
        printf("The target element is not present ");
    }
}