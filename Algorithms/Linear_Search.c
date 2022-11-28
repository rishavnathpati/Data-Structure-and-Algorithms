#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Linear search
int linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Enter the key to search: ");
    int key;
    scanf("%d", &key);
    int index = linear_search(arr, n, key);
    if (index == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at index %d", index);
    }
    return 0;
}