#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 20
char stack[n][100];
char backs[n][100];
int top1 = -1;
int top2 = -1;
void push1(char str[])
{
    top1++;
    strcpy(stack[top1], str);
}
void push2(char str[])
{
    top2++;
    strcpy(backs[top2], str);
}
void pop1()
{
    top2++;
    strcpy(backs[top2], stack[top1]);
    top1--;
}
int pop2()
{
    top1++;
    strcpy(stack[top1], backs[top2]);
    top2--;
    printf("Done");
    return 0;
}

void display()
{
    if (top1 == -1)
        printf("Nothing");
    for (int i = 0; i <= top1; i++)
    {
        printf("%s", stack[i]);
    }
}
int main()
{
    int ch;
    char str[100];
    do
    {
        printf("\n\
        1. Push\n\
        2. Backward \n\
        3. Forward\n\
        4. Display\n\
        5. Exit \n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            printf("Enter URL to visit: ");
            scanf("%s", str);
            push1(str);
            break;
        case 2:
            pop1();
            break;
        case 3:
            pop2();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exit");
            break;
        default:
            printf("Wrong choice");
            break;
        }
    } while (ch != 5);
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX 100

// // Stack using array

// char stack[MAX][100];
// int top = -1;

// void push(char str[])
// {
//     top++;
//     strcpy(stack[top], str);
// }

// void pop()
// {
//     top--;
// }

// void display()
// {
//     if (top == -1)
//         printf("Nothing");
//     for (int i = 0; i <= top; i++)
//     {
//         printf("%s", stack[i]);
//     }
// }

// int main()
// {
//     int ch;
//     char str[100];
//     do
//     {
//         printf("\n\
//         1. Push\n\
//         2. Backward \n\
//         3. Forward\n\
//         4. Display\n\
//         5. Exit \n");
//         printf("\nEnter your choice: ");
//         scanf("%d", &ch);
//         switch (ch)
//         {

//         case 1:
//             printf("Enter URL to visit: ");
//             scanf("%s", str);
//             push(str);
//             break;
//         case 2:
//             pop();
//             break;
//         case 3:
//             pop();
//             break;
//         case 4:
//             display();
//             break;
//         case 5:
//             printf("Exit");
//             break;
//         default:
//             printf("Wrong choice");
//             break;
//         }
//     } while (ch != 5);
//     return 0;
// }