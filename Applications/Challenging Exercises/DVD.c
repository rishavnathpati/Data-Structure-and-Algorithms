#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40

int rear = -1;
int front = -1;
char q[MAX];
char b[30];
char at[] = {"abcdefghij"};
int i = 0, j = 0;

int isempty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if ((rear + 1) % 10 == front)
        return 1;
    else
        return 0;
}
void write()
{
    if (isfull())
        printf("Full");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % 10;
        q[rear] = at[i++];
    }
}
void disp()
{
    int j;
    printf("Output");
    for (j = 0; j < 20; j++)
        printf("%c", b[j]);
    printf("\n");
}
void read()
{
    if (rear == front)
        printf("Disk Empty");
    else
    {
        char d[54];
        d[j] = q[front];
        disp();
        front = (front + 1) % 10;

        j++;
    }
}
void display()
{
    int i;
    printf("In Buffer\n");
    for (i = 0; i < MAX; i++)
        printf("%c", q[i]);
    printf("\n");
}
int main()
{
    while (isfull() != 1)
    {
        write();
    }
    int ch;
    display();
    while (ch != 2)
    {
        printf("1 to read\n");
        printf("2 to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            read();

            write();
            display();
        }
    }
}