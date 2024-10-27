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
    int k;
    printf("Enter the position which you want to delete : ");
    scanf("%d",&k);
    for( int i=k ; i<n ; i++){
        arr[i]=arr[i+1];
    }
    for( int i=0 ; i<n-1 ; i++ ){
        printf("%d ",arr[i]);
    }
}