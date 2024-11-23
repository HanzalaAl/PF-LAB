// Write a recursive function that calculates the sum of digits of a number. For example, if
// the input is 123, the output should be 6.

#include <stdio.h>

int sum(int n);

int main(){

    int n;
    printf("enter a number");
    scanf("%d",&n);

    int result = sum(n);
    printf("the sum of digits is %d",result);

    return 0;
}

int sum(int n){
    if (n==0){
        return 0;
    } else {
        int last = n%10;
        return last + sum(n/10);
    }
}
