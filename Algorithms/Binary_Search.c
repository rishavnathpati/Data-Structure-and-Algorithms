// Program for binary search

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Employee Structure
struct Employee
{
    int id;
    char name[20];
    int salary;
};

// Binary search
int binary_search(struct Employee arr[], int n, int key)
{
    int comparisons = 0;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid].id == key)
        {
            printf("Number of comparisons: %d\n", comparisons);
            return mid;
        }
        else if (arr[mid].id < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        comparisons++;
    }
    printf("Number of comparisons: %d\n", comparisons);
    return -1;
}

//Bubble sort the Employee array
void bubble_sort(struct Employee arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].id > arr[j + 1].id)
            {
                struct Employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    struct Employee arr[] = {{1, "A", 1000}, {2, "B", 2000}, {3, "C", 3000}, {4, "D", 4000}, {5, "E", 5000}, {6, "F", 6000}, {7, "G", 7000}, {8, "H", 8000}, {9, "I", 9000}, {10, "J", 10000}, {11, "K", 11000}, {12, "L", 12000}, {13, "M", 13000}, {14, "N", 14000}, {15, "O", 15000}, {16, "P", 16000}, {17, "Q", 17000}, {18, "R", 18000}, {19, "S", 19000}, {20, "T", 20000}};
    bubble_sort(arr, 20);
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("\nEnter the key to search: ");
    int key;
    scanf("%d", &key);
    int index = binary_search(arr, n, key);
    if (index == -1)
    {
        printf("\nElement not found");
    }
    else
    {
        printf("\nElement found at index %d", index);
        printf("\nEmployee ID: %d", arr[index].id);
        printf("\nEmployee Name: %s", arr[index].name);
        printf("\nEmployee Salary: %d\n", arr[index].salary);
    }
    return 0;
}