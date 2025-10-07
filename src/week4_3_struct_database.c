/*
 * week4_3_struct_database.c
 * Author: Jayakodi Arachchige Thisendie Thehasna Jayakody
 * Student ID: 233AEB009
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct Student with fields: name, id, grade
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // Allocate memory for n Student structs
    students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read student data
    for (int i = 0; i < n; i++) {
        printf("Enter data for student %d (name id grade): ", i + 1);
        if (scanf("%s %d %f", students[i].name, &students[i].id, &students[i].grade) != 3) {
            printf("Invalid input.\n");
            free(students);
            return 1;
        }
    }

    // Display all student records
    printf("\nID\tName\t\tGrade\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-10s\t%.1f\n", students[i].id, students[i].name, students[i].grade);
    }

    // Free allocated memory
    free(students);

    return 0;
}
