#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

int compareBySalary(const void *a, const void *b) {
    const Employee *empA = (const Employee *)a;
    const Employee *empB = (const Employee *)b;

    if (empA->salary < empB->salary) return -1;
    else if (empA->salary > empB->salary) return 1;
    else return 0;
}

int main() {
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    Employee *employees = (Employee *)malloc(n * sizeof(Employee));
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        getchar();
        printf("Name: ");
        fgets(employees[i].name, 50, stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    qsort(employees, n, sizeof(Employee), compareBySalary);

    printf("\nEmployees sorted by salary:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }

    free(employees);

    return 0;
}
