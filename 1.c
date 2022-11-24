// Students of a Programming class arrive to submit assignments.
// Their register numbers are stored in a LIFO list in the order in which the assignments are submitted

#include <stdio.h>
#define max 100

int top = -1;
char a[max][100];

int isempty();
int isfull();
void push(char x[100]);
void pop();
void display();

int main()
{
    char x[100];
    int ch = 1, n;
    while (ch != 4)
    {
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the registration no. of student: ");
            scanf("%s", x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    }
    printf("Enter the first n number of required record\n");
    scanf("%d", &n);
    while (top >= n)
    {
        pop();
    }
    printf("The first %d students are\n", n);
    display();
    return 0;
}
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if (top == max - 1)
        return 1;
    else
        return 0;
}
void push(char x[100])
{
    int i;
    if (isfull())
        printf("stack is full\n");
    else
    {
        top++;
        for (i = 0; i < 100; i++)
        {
            a[top][i] = x[i];
        }
    }
}
void pop()
{
    if (isempty())
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("deleted element is %s\n", a[top]);
        top--;
    }
}
void display()
{
    int i;
    if (isempty())
        printf("stack is empty\n");
    else
    {
        for (i = 0; i <= top; i++)
            printf("%s\n", a[i]);
    }
}