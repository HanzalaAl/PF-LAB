// Q3. Without using standard library functions (strlen, strcpy, etc.), write a program to:
// Find the length of a string using pointers.
// Reverse a string using pointers.
// Concatenate two strings using pointers.

#include <stdio.h>

int findlength(const char *str){
    const char *ptr = str;
    int length =0 ;

    while(*ptr != '\0'){
        length++;
        ptr++;
    }

    return length;
}

void reverseString(char *str){
    char *start = str;
    char *end =  str;
    char temp;

    while(*end != '\0'){
        end++;
    }
    end--;

    while(start < end){
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void concat(char *str1 , const char *str2){

    while(*str1 != '\0'){
        str1++;
    }

    while(*str2 != '\0'){
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';
}