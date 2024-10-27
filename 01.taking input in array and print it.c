#include<stdio.h>
int main(){
    int n ;
    printf("Enter the number of elements you want : ");
    scanf("%d",&n);
    int arr[n];
    for( int i=0 ; i<n ; i++ ){
        printf("Enter the number for index %d : ",i);
        scanf( "%d",&arr[i]);
    }
    for( int i=0 ; i<n ; i++ ){
        printf("%d ",arr[i]);
    }
}