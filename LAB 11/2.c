#include <stdio.h>

struct Employee {
    char name[50];
    int id;
    float salary;
};

void writeEmployeeDataToFile() {
    FILE *file = fopen("employee_data.dat", "wb");
    struct Employee emp1 = {"John Doe", 1, 50000};
    struct Employee emp2 = {"Jane Smith", 2, 60000};
    
    fwrite(&emp1, sizeof(struct Employee), 1, file);
    fwrite(&emp2, sizeof(struct Employee), 1, file);
    
    fclose(file);
}

void readEmployeeDataFromFile() {
    FILE *file = fopen("employee_data.dat", "rb");
    struct Employee emp;
    float totalSalary = 0;
    
    while (fread(&emp, sizeof(struct Employee), 1, file)) {
        totalSalary += emp.salary;
    }
    
    printf("Total salary expense: %.2f\n", totalSalary);
    fclose(file);
}

int main() {
    writeEmployeeDataToFile();
    readEmployeeDataFromFile();
    return 0;
}
