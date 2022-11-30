// 2.Implement linear search to the find an elements in a character array  whether both  Z and I are available or not in the given array?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[100];
    int i, flag = 0;
    printf("Enter the string:");
    scanf("%s", arr);
    for (i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == 'Z' || arr[i] == 'I' || arr[i] == 'z' || arr[i] == 'i')
        {
            flag++;
            if(flag==2)
            {
                printf("Both Z and I are available in the given array");
                break;
            }
        }
    }
    if (flag < 2)
    {
        printf("Z and I are not available in the given array");
    }
    return 0;
}