#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays into a single array
void merge(int *array, int left, int mid, int right) {
  // Calculate the sizes of the two arrays to be merged
  int size1 = mid - left + 1;
  int size2 = right - mid;

  // Create temporary arrays to hold the two arrays to be merged
  int left_array[size1], right_array[size2];

  // Copy the data from the original array into the temporary arrays
  for (int i = 0; i < size1; i++) {
    left_array[i] = array[left + i];
  }
  for (int i = 0; i < size2; i++) {
    right_array[i] = array[mid + 1 + i];
  }

  // Merge the two temporary arrays back into the original array
  int i = 0, j = 0, k = left;
  while (i < size1 && j < size2) {
    if (left_array[i] <= right_array[j]) {
      array[k] = left_array[i];
      i++;
    } else {
      array[k] = right_array[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements from the left array, if any
  while (i < size1) {
    array[k] = left_array[i];
    i++;
    k++;
  }

  // Copy the remaining elements from the right array, if any
  while (j < size2) {
    array[k] = right_array[j];
    j++;
    k++;
  }
}

// Recursive function to sort an array using merge sort
void merge_sort(int *array, int left, int right) {
  if (left < right) {
    // Calculate the middle index of the array
    int mid = left + (right - left) / 2;

    // Sort the left and right halves of the array
    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);

    // Merge the two sorted halves
    merge(array, left, mid, right);
  }
}

int main() {
  // Initialize an array to be sorted
  int array[] = {3, 5, 1, 6, 8, 2, 9, 4, 7};
  int size = sizeof(array) / sizeof(array[0]);

  // Print the array before sorting
  printf("Original array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // Sort the array
  merge_sort(array, 0, size - 1);

  // Print the array after sorting
  printf("Sorted array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
