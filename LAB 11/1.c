#include <stdio.h>

struct Employee {
    char name[50];
    int emp_id;
    float salary;
};

struct Department {
    struct Employee employees[10];
    int num_employees;
};

float calculateTotalSalary(struct Department dept) {
    float totalSalary = 0;
    for (int i = 0; i < dept.num_employees; i++) {
        totalSalary += dept.employees[i].salary;
    }
    return totalSalary;
}

int main() {
    struct Department dept;
    dept.num_employees = 2;
    
    struct Employee emp1 = {"John Doe", 1, 50000};
    struct Employee emp2 = {"Jane Smith", 2, 60000};
    
    dept.employees[0] = emp1;
    dept.employees[1] = emp2;
    
    float totalSalary = calculateTotalSalary(dept);
    printf("Total salary of all employees: %.2f\n", totalSalary);
    
    return 0;
}
