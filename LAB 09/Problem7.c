// Create a function that returns the maximum and minimum element in an integer array. Use this
// function in the main program to find the maximum and minimum from an array entered by the
// user.

#include <stdio.h>

void maxmin(int arr[] , int n);

int main(){
    int n,value;
    printf("how many numbers do you want to input: ");
    scanf("%d",&n);
    int arr[n];
    for (int i =0 ; i<n ; i++){
        printf("enter values(less than 9999):");
        scanf("%d",&value);
        arr[i] = value;
    }
    maxmin(arr,n);
    return 0;
}

void maxmin(int arr[] , int n){
    int max = arr[0] , min= arr[0] ;
    for (int i = 0 ; i<=n-1 ; i++){
        if (arr[i] > max){
            max = arr[i];
        }
        if (min > arr[i]){
            min = arr[i];
        }
    }
    printf("maximum number is : %d\n",max);
    printf("minimum number is : %d\n",min);
}


