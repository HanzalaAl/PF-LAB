// 1. Write a recursive function that takes an array and its size as input and prints all the
// elements.

#include <stdio.h>

void print(int arr[],int n , int i);

int main(){

    int i =0; int n =9;
    int arr[] = {1,2,3,4,5,6,7,8,9};
    print(arr,9,0);

    return 0;
}

void print(int arr[],int n,int i){
    if(i==n){
        return;
    }else{
        printf("%d\n",arr[i]);
        i++;
        print(arr,9,i);
    }
}
