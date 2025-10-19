// week5_task3_student_management_system.c
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
  char name[NAME_LEN];
  int id;
  float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int* count);
void list_students(Student arr[], int count);

int main(void) {
  Student students[MAX_STUDENTS];
  int count = 0;
  int choice;

  // Load data at startup
  count = load_students(students);

  do {
    printf("\n=== Student Management System ===\n");
    printf("1. List students\n");
    printf("2. Add student\n");
    printf("3. Save and Exit\n");
    printf("Select an option: ");
    if (scanf("%d", &choice) != 1) {
      printf("Invalid input. Try again.\n");
      while (getchar() != '\n');  // clear input
      continue;
    }
    getchar();  // clear newline

    switch (choice) {
      case 1:
        list_students(students, count);
        break;
      case 2:
        add_student(students, &count);
        break;
      case 3:
        save_students(students, count);
        printf("Data saved. Goodbye!\n");
        break;
      default:
        printf("Invalid option. Try again.\n");
    }
  } while (choice != 3);

  return 0;
}

int load_students(Student arr[]) {
  FILE* fp = fopen(DATA_FILE, "r");
  if (fp == NULL) {
    printf("No existing data found. Starting fresh.\n");
    return 0;
  }

  int count = 0;
  while (fscanf(fp, "%49s %d %f", arr[count].name, &arr[count].id,
                &arr[count].gpa) == 3) {
    count++;
    if (count >= MAX_STUDENTS) break;
  }
  fclose(fp);
  printf("Loaded %d students from %s.\n", count, DATA_FILE);
  return count;
}

void save_students(Student arr[], int count) {
  FILE* fp = fopen(DATA_FILE, "w");
  if (fp == NULL) {
    perror("Error saving students");
    return;
  }

  for (int i = 0; i < count; i++) {
    fprintf(fp, "%s %d %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
  }
  fclose(fp);
}

void add_student(Student arr[], int* count) {
  if (*count >= MAX_STUDENTS) {
    printf("Cannot add more students.\n");
    return;
  }

  Student s;
  printf("Enter name: ");
  fgets(s.name, NAME_LEN, stdin);
  s.name[strcspn(s.name, "\n")] = '\0';  // remove newline

  printf("Enter ID: ");
  scanf("%d", &s.id);
  printf("Enter GPA: ");
  scanf("%f", &s.gpa);
  getchar();  // clear newline

  arr[*count] = s;
  (*count)++;
  printf("Student added successfully!\n");
}

void list_students(Student arr[], int count) {
  if (count == 0) {
    printf("No students to display.\n");
    return;
  }
  printf("\n%-5s %-20s %-5s\n", "ID", "Name", "GPA");
  printf("---------------------------------\n");
  for (int i = 0; i < count; i++) {
    printf("%-5d %-20s %.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
  }
}
