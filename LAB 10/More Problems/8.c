// Write a recursive function linearSearch that takes an array, its size, the target element
// to search for, and the current index. It checks if the target is at the current index and
// continues searching in the subsequent indices until it either finds the target or exhausts
// the array.

#include <stdio.h>

void linearSearch(int arr[],int size, int target,int index);

int main(){
    int arr[] ={6,17,42,68,71,57,69,1,2,5};
    int size = 10;
    int target;
    int index =0;

    printf("enter the number you want to find:");
    scanf("%d",&target);

    linearSearch(arr,size,target,index);
    return 0;
}

void linearSearch(int arr[],int size, int target, int index){
    if(index == size){
        printf("number not found");
        return;
    } 
    if(arr[index] == target){
        printf("number found at index %d",index);
        return;
    }
    linearSearch(arr,size,target,index+1);
}

