#include<stdio.h>
void bubble( int arr[] , int n ){
    for( int i=0 ; i<n-1 ; i++ ){
        for( int j=0 ; j<n-i-1 ; j++ ){
            if( arr[j] > arr[j+1] ){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main(){
    int n;
    printf("Enter the number of elements you want to take : ");
    scanf("%d",&n);
    int arr[n];
    for( int i=0 ; i<n ; i++ ){
        printf("Enter the element for index  %d :",i);
        scanf("%d",&arr[i]);
    }
    int flag=1;
    for( int i=0 ; i<n-1 ; i++ ){
        if( arr[i]>arr[i+1]){
            flag=0;
        }
    }
    if( flag==1 ){
        printf("The array is already sorted ");
        return 0;
    }
    bubble( arr , n );
    for( int i=0 ; i<n ; i++ ){
        printf("%d ",arr[i]);
    }
}