// Q1. Write a program to reverse an array using pointers without using any additional arrays.

#include <stdio.h>

void reverseArray(int *arr , int size){
    int *start =  arr ;
    int *end = arr + size -1;

    while(start < end){
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main(){
    int n;

    printf("enter the size of the array : ");
    scanf("%d",&n);

    int arr[n];

    printf("enter elements: ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }

    reverseArray(arr,n);

    printf("reversed array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }

    return 0;
    
}