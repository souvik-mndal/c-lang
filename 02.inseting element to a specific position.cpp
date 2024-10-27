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
    printf("Enter the position where you want to insert : ");
    scanf("%d",&k);
    for( int i=n-1 ; i>=k ; i--){
        arr[i+1]=arr[i];
    }
    int m;
    printf("Enter the number you want to insert : ");
    scanf("%d",&m);
    arr[k]=m;
    for( int i=0 ; i<=n ; i++ ){
        printf("%d ",arr[i]);
    }
}