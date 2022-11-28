// 1.	Implement the heap sort to the given values 23 9 44 65 12 99 86 33 12 to get an ascending order?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int i, j, k, n, temp, heap[100], size;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &heap[i]);
    }
    heap[0] = 9999;
    for (i = 2; i <= n; i++)
    {
        k = i;
        j = k / 2;
        while (heap[j] < heap[k] && j >= 1)
        {
            temp = heap[j];
            heap[j] = heap[k];
            heap[k] = temp;
            k = j;
            j = k / 2;
        }
    }
    size = n;
    while (size > 1)
    {
        temp = heap[1];
        heap[1] = heap[size];
        heap[size] = temp;
        size--;
        k = 1;
        j = k * 2;
        while (j <= size)
        {
            if (heap[j] < heap[j + 1] && j < size)
                j = j + 1;
            if (heap[k] < heap[j] && j <= size)
            {
                temp = heap[k];
                heap[k] = heap[j];
                heap[j] = temp;
                k = j;
                j = 2 * k;
            }
            else
                break;
        }
    }
    printf("The sorted elements are: ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}