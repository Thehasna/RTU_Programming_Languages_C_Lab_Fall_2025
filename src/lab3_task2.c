/*
 * Lab 3, Task 2
 * Student Name: Thisendie Jayakody
 * Student ID: 233AEB009
 *
 * Practice using pointers as function parameters.
 * Implement:
 *   - swap (exchange values of two ints)
 *   - modify_value (multiply given int by 2)
 */

#include <stdio.h>

// Function prototypes
void swap(int* x, int* y);
void modify_value(int* x);

int main(void) {
  int a = 3, b = 7;

  printf("Before swap: a=%d, b=%d\n", a, b);
  swap(&a, &b);
  printf("After swap: a=%d, b=%d\n", a, b);

  modify_value(&a);
  printf("After modify_value: a=%d\n", a);

  return 0;
}

// Swap two integers
void swap(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

// Multiply value by 2 (modify via pointer)
void modify_value(int* x) { *x = *x * 2; }
