// 2. Write a recursive function that takes a string as input and returns the reversed string.

#include <stdio.h>
#include <string.h>
void reverse(char str[],int n );

int main(){
    
    char str[100];
    printf("enter a word you want to reverse: ");
    scanf("%s",str);

    int n= strlen(str);
    reverse(str,n-1);
    
    return 0;
}

void reverse(char str[],int n){
    if (n<0){
        return;
    } 
        printf("%c",str[n]);
        reverse(str,n-1);
}