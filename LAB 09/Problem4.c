// Implement a function that checks if a given integer is a prime number. Use this function in the
// main program to check if numbers entered by the user are prime.

#include <stdio.h>

void prime(int n);

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    prime(n);
    return 0;
}

void prime(int n) {
    if (n <= 1) {
        printf("Not a prime number\n");
        return;
    }

    int flag = 0;
    for (int i = 2; i * i <= n; i++) { 
        if (n % i == 0) { 
            flag = 1;
            break;  
        }
    }

    if (flag == 0) {
        printf("Prime number\n");
    } else {
        printf("Not a prime number\n");
    }
}
