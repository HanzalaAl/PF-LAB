// Write a recursive function bubbleSort that takes an array and its size. It performs the
// bubble sort algorithm by repeatedly comparing adjacent elements and swapping them if
// they are in the wrong order.

#include <stdio.h>

void bubblesort(int arr[],int n);

int main(){
    
    int n;
    printf("enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    
    for(int i=0; i<n ; i++){
        printf("enter element %d :",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Original Array: ");
    for(int i=0 ; i<n ; i++ ){
        printf("%d\t",arr[i]);
    }
    printf("\n");

    bubblesort(arr,n);
    
    printf("sorted Array: ");
    for(int i=0 ; i<n ; i++ ){
        printf("%d\t",arr[i]);
    }

    return 0;
}

void bubblesort(int arr[],int n){
    int temp;
    if(n==1){
        return;
     } 
    for(int i =0; i <n-1 ;i++) {
        if(arr[i]>arr[i+1]){
           temp = arr[i];
           arr[i] = arr[i+1];
           arr[i+1] = temp;
        }
      }
    bubblesort(arr,n-1);
}