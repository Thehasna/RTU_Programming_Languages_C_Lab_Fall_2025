// lab2_1.c
// Lab 2: Control Flow & Functions
// Task 1 – Sum 1..n
// Author: Thisendie Jayakody, [233AEB009]

#include <stdio.h>

int sum_to_n(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int main(void) {
  int n;

  printf("Enter a positive integer n: ");
  if (scanf("%d", &n) != 1) {
    printf("Invalid input.\n");
    return 1;
  }

  if (n < 1) {
    printf("Error: n must be a positive integer.\n");
    return 1;
  }

  int result = sum_to_n(n);
  printf("The sum of numbers from 1 to %d is %d\n", n, result);

  return 0;
}
