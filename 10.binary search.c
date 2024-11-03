#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of elements you want to take : ");
    scanf("%d",&n);
    int arr[n];
    for( int i=0 ; i<n ; i++ ){
        printf("Enter the element for index  %d :",i);
        scanf("%d",&arr[i]);
    }
    int x;
    printf("Enter the target element you want to find : ");
    scanf("%d",&x);
    int s=0 , e=n-1;
    int flag=0;
    while( s<=e ){
        int mid = s+(e-s)/2;
        if( arr[mid]==x ){
            flag=1;
            printf("The element is present at index : %d", mid);
            break;
        }
        else if( arr[mid]<x ){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    if( flag==0 ){
        printf("Target element not found ");
    }
}
