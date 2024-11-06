// Create a C program that swaps the values of two integers using a user-defined function,
// swapIntegers. The user inputs two integer values, and the program uses the function to swap
// them. It should perform the swap and display the updated values.

// Create a C program that swaps the values of two integers using a user-defined function,
// swapIntegers. The user inputs two integer values, and the program uses the function to swap
// them. It should perform the swap and display the updated values.

#include <stdio.h>

void swap(int *a , int *b);

int main(){
    int a ,b;
    printf("enter number1 :");
    scanf("%d",&a);
    
    printf("enter number2 :");
    scanf("%d",&b);

    printf("previous value1 : %d\n",a);
    printf("previous value2 : %d\n",b);

    swap(&a,&b);
}

void swap(int *a , int *b){
    int temp = *a;
    *a =  *b;
    *b = temp;

    printf("new value1 : %d\n",*a );
    printf("new value2 : %d\n",*b );
}
