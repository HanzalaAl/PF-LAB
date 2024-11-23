#include <stdio.h>

struct Course {
    char name[50];
    char code[10];
    char instructor[50];
};

struct Student {
    char name[50];
    int roll_no;
    struct Course courses[5];
    int num_courses;
};

void saveStudentDataToFile(struct Student students[], int num_students) {
    FILE *file = fopen("student_data.dat", "wb");
    fwrite(students, sizeof(struct Student), num_students, file);
    fclose(file);
}

void displayStudentCourses(struct Student student) {
    printf("Courses enrolled by %s:\n", student.name);
    for (int i = 0; i < student.num_courses; i++) {
        printf("%s - %s by %s\n", student.courses[i].code, student.courses[i].name, student.courses[i].instructor);
    }
}

void generateCourseEnrollmentReport(struct Student students[], int num_students) {
    int courseCount[5] = {0};
    for (int i = 0; i < num_students; i++) {
        for (int j = 0; j < students[i].num_courses; j++) {
            courseCount[j]++;
        }
    }
    
    printf("Course enrollment report:\n");
    for (int i = 0; i < 5; i++) {
        printf("Course %d: %d students enrolled\n", i + 1, courseCount[i]);
    }
}

int main() {
    struct Course course1 = {"Math", "MATH101", "Dr. Smith"};
    struct Course course2 = {"Physics", "PHYS101", "Dr. Johnson"};
    
    struct Student student1 = {"John Doe", 1, {course1, course2}, 2};
    struct Student student2 = {"Jane Smith", 2, {course1}, 1};
    
    struct Student students[] = {student1, student2};
    
    saveStudentDataToFile(students, 2);
    displayStudentCourses(student1);
    generateCourseEnrollmentReport(students, 2);
    
    return 0;
}
