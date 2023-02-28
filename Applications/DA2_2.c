#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        printf("\nThe mid value is: %d at position %d", arr[mid], mid);
        if (arr[mid] == x)
        {
            // printf("\nThe mid value is: %d", arr[mid]);
            return mid;
        }
        if (arr[mid] > x)
        {
            printf("\nThe mid value %d is greater than %d", arr[mid], x);
            return binarySearch(arr, l, mid - 1, x);
        }
        else if (arr[mid] < x)
        {
            printf("\nThe mid value %d is less than %d", arr[mid], x);
            return binarySearch(arr, mid + 1, r, x);
        }
    }
    return -1;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

// Bubble sort function return the array from the function
int* bubbleSort(int arr[], int n, int *pos_count)
{
    int i, j, temp;
    int count = 0;
    for (i = 0; i < n - 1; i++)
    {
        // Keep track of duplicate elements
        int duplicate = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            count++;
        }
    }
    printf("\nThe sorted array is: ");
    printArray(arr, n);
    return arr;
}

int main()
{
    // take input an array of N elements
    int N;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &N);
    int input[N];
    printf("\nEnter the elements of the array: \n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input[i]);
    }
    // print the input array
    printf("The input array is: ");
    printArray(input, N);

    // create two arrays for positive and negative numbers
    int pos[MAX], neg[MAX];
    int pos_count = 0, neg_count = 0;

    // call Bubble Sort function
    bubbleSort(input, N, &pos_count);

    // Perform and print each steps like mid value less than greater than comparison in Binary search
    int key;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);
    int result = binarySearch(input, 0, N - 1, key);
    if (result == -1)
    {
        printf("\nElement is not present in the array");
    }
    else
    {
        printf("\nElement is present at index %d", result);
    }
    return 0;
}

// 1, -7, 9, -3, -12, 8, -2, 15, 6, -11, 4, -9, 17, -14, 10, -6, 3, -1, 13, -5
