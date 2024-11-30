#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, new_n;
    int *arr;
    int sum = 0, new_sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum of the first %d elements: %d\n", n, sum);

    new_n = 2 * n;
    arr = (int *)realloc(arr, new_n * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    printf("Enter %d more integers:\n", n);
    for (int i = n; i < new_n; i++) {
        scanf("%d", &arr[i]);
        new_sum += arr[i];
    }

    new_sum += sum;
    printf("New sum: %d\n", new_sum);

    free(arr);
    return 0;
}
