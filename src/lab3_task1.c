/*
 * Lab 3, Task 1
 * Student Name:Thisendie Jayakody
 * Student ID: 233AEB009
 *
 * Implement array algorithms:
 *   - find minimum value
 *   - find maximum value
 *   - calculate sum
 *   - calculate average
 */

#include <limits.h>
#include <stdio.h>

// Function prototypes
int array_min(int arr[], int size);
int array_max(int arr[], int size);
int array_sum(int arr[], int size);
float array_avg(int arr[], int size);

int main(void) {
  int arr[] = {10, 20, 5, 30, 15};
  int size = 5;

  printf("Min: %d\n", array_min(arr, size));
  printf("Max: %d\n", array_max(arr, size));
  printf("Sum: %d\n", array_sum(arr, size));
  printf("Avg: %.2f\n", array_avg(arr, size));

  return 0;
}

// Return smallest element
int array_min(int arr[], int size) {
  int my_min = INT_MAX;
  for (int i = 0; i < size; i++) {
    if (arr[i] < my_min) {
      my_min = arr[i];
    }
  }
  return my_min;
}

// Return largest element
int array_max(int arr[], int size) {
  int my_max = INT_MIN;
  for (int i = 0; i < size; i++) {
    if (arr[i] > my_max) {
      my_max = arr[i];
    }
  }
  return my_max;
}

// Return sum of all elements
int array_sum(int arr[], int size) {
  int total = 0;
  for (int i = 0; i < size; i++) {
    total += arr[i];
  }
  return total;
}

// Return average as float
float array_avg(int arr[], int size) {
  if (size == 0) return 0.0f;
  int total = array_sum(arr, size);
  return (float)total / size;
}
