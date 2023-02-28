// Try to create an array of N elements as input which consists of Positive, Negative numbers and also the duplicate values.
// Perform any sorting procedure to get output as two sorted array one with positive numbers and one with negative numbers and print the number of comparisons made for each sorted array and aslo the say count for the each the duplicate values.
// Exapmle : 
// Output1[15]={-1,-1,-3,-8,-15} and print Number of Comparisons
// Output2[15]={0,1,3,3,4,4,4,7,9,10} and print Number of Comparisons
// -1 has been present twice
// + 3 has been present twice
// + 4 has been present thrice

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX 100
// int main()
// {
//   // take input an array of N elements
//   int N;
//   printf("Enter the number of elements in the array: ");
//   scanf("%d", &N);
//   int input[N];
//   printf("Enter the elements of the array: ");
//   for (int i = 0; i < N; i++)
//   {
//     scanf("%d", &input[i]);
//   }
//   // print the input array
//   printf("The input array is: ");
//   print_array(input, N);

//   // create two arrays for positive and negative numbers
//   int pos[MAX], neg[MAX];
//   int pos_count = 0, neg_count = 0;

//   // call Bubble Sort function
//   bubbleSort(input, N, &pos_count);

//   // call selection sort function

//   // create two arrays for positive and negative numbers
//   int pos[MAX], neg[MAX];
//   int pos_count = 0, neg_count = 0;
// }

// // Perform bubble sorting algo on the array with a fuction and return the array  and print the number of comparisons made and print the count for the each of the duplicate values.
// void bubbleSort(int arr[], int n, int *pos_count)
// {
//   int i, j, temp;
//   int count = 0;
//   for (i = 0; i < n - 1; i++)
//   {
//     // Keep track of duplicate elements
//     int duplicate = 0;
//     for (j = 0; j < n - i - 1; j++)
//     {

//       if (arr[j] > arr[j + 1])
//       {
//         temp = arr[j];
//         arr[j] = arr[j + 1];
//         arr[j + 1] = temp;
//       }
//       count++;
//     }
//   }
//   printf("The sorted array is: ");
//   print_array(arr, n);
//   printf("The number of comparisons made is: %d", count);
// }

// // Function to perform selection sort
// void selectionSort(int arr[], int n, int *num_comparisons)
// {
//   int i, j, min_index, temp;

//   // Perform n-1 passes
//   for (i = 0; i < n - 1; i++)
//   {

//     // Set the minimum index to the current element
//     min_index = i;

//     // Check all the remaining elements
//     for (j = i + 1; j < n; j++)
//     {

//       // If a smaller element is found, update the minimum index
//       if (arr[j] < arr[min_index])
//       {
//         min_index = j;
//       }

//       // Increment the number of comparisons
//       (*num_comparisons)++;
//     }

//     // If the minimum index is not the current element, swap them
//     if (min_index != i)
//     {
//       temp = arr[i];
//       arr[i] = arr[min_index];
//       arr[min_index] = temp;
//     }
//   }
// }

// // Function to print the array
// void print_array(int arr[], int N)
// {
//   for (int i = 0; i < N; i++)
//   {
//     printf("%d ", arr[i]);
//   }
// }

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort()
int compare(const void *a, const void *b)
{
  // Cast the void pointers to int pointers
  int x = *((int *)a);
  int y = *((int *)b);

  // Return the difference between the values
  // This will sort the array in ascending order
  return x - y;
}

void count_multiple(int x[], int n)
{
  for (int i = 0; i < n; i++)
  {int count = 1;
    if (i != 0 && x[i - 1] != x[i])
    {
      
      for (int j = i + 1; j < n; j++)
      {
        if (x[i] == x[j])
        {
          count++;
        }
        
      }
    }
    if (count != 1)
        {
          printf("%d has been present %d times\n", x[i], count);
        }
  }
}

int main()
{

  int arr[15] = {10, 4, -3, -1, 0, 4, 3, -15, -8, 4, -1, 9, 3, 1, 7};

  // print the array
  printf("\nThe array is:  \n");
  for (int i = 0; i < 15; i++)
  {
    printf("%d ", arr[i]);
  }

  // Allocate memory for the positive and negative arrays
  int *positive = (int *)malloc(sizeof(int) * 15);
  int *negative = (int *)malloc(sizeof(int) * 15);

  // Indexes for the positive and negative arrays
  int p = 0;
  int n = 0;

  // Count the number of comparisons made by qsort()
  int comparisons = 0;

  // Iterate over the original array and split the values
  // into positive and negative arrays
  for (int i = 0; i < 15; i++)
  {
    if (arr[i] > 0)
    {
      positive[p] = arr[i];
      p++;
    }
    else if (arr[i] < 0)
    {
      negative[n] = arr[i];
      n++;
    }

    // Count the number of comparisons
    comparisons++;
  }

  // Sort the positive and negative arrays using qsort()
  qsort(positive, p, sizeof(int), compare);
  qsort(negative, n, sizeof(int), compare);

  // Print the sorted arrays
  printf("\nPositive numbers: ");
  for (int i = 0; i < p; i++)
  {
    printf("%d ", positive[i]);
  }
  printf("\n");

  printf("\nNegative numbers: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", negative[i]);
  }
  printf("\n");

  // Print the number of comparisons made by qsort()
  printf("\nNumber of comparisons: %d\n", comparisons);

  // Free the memory allocated for the arrays
  free(positive);
  free(negative);

  count_multiple(arr, 15);

  return 0;
}