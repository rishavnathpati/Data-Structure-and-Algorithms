// Write a program to implement a 3-stacks of size ‘m’ in an array of size ‘n’ with all the basic operations such as IsEmpty(i), Push(i), Pop(i), IsFull(i) where ‘i’ denotes the stack number (1,2,3), m n/3.
// Stacks are not overlapping each other. Leftmost stack facing the left direction and other two stacks are facing in the right direction.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top1 = -1;
int top2 = MAX / 3;
int top3 = (MAX / 3) * 2;

void push(int stackNum, int data)
{
    if (stackNum == 1)
    {
        if (top1 == MAX / 3 - 1)
        {
            printf("Stack is full");
            return;
        }
        stack[++top1] = data;
    }
    else if (stackNum == 2)
    {
        if (top2 == (MAX / 3) * 2 - 1)
        {
            printf("Stack is full");
            return;
        }
        stack[++top2] = data;
    }
    else if (stackNum == 3)
    {
        if (top3 == MAX - 1)
        {
            printf("Stack is full");
            return;
        }
        stack[++top3] = data;
    }
    else
    {
        printf("Invalid stack number");
    }
}

int pop(int stackNum)
{
    if (stackNum == 1)
    {
        if (top1 == -1)
        {
            printf("Stack is empty");
            return -1;
        }
        return stack[top1--];
    }
    else if (stackNum == 2)
    {   
        if (top2 == MAX / 3)
        {
            printf("Stack is empty");
            return -1;
        }
        return stack[top2--];
    }
    else if (stackNum == 3)
    {
        if (top3 == (MAX / 3) * 2)
        {
            printf("Stack is empty");
            return -1;
        }
        return stack[top3--];
    }
    else
    {
        printf("Invalid stack number");
        return -1;
    }
}

int isEmpty(int stackNum)
{
    if (stackNum == 1)
    {
        if (top1 == -1)
        {
            return 1;
        }
        return 0;
    }
    else if (stackNum == 2)
    {
        if (top2 == MAX / 3)
        {
            return 1;
        }
        return 0;
    }
    else if (stackNum == 3)
    {
        if (top3 == (MAX / 3) * 2)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        printf("Invalid stack number");
        return -1;
    }
}

int isFull(int stackNum)
{
    if (stackNum == 1)
    {
        if (top1 == MAX / 3 - 1)
        {
            return 1;
        }
        return 0;
    }
    else if (stackNum == 2)
    {
        if (top2 == (MAX / 3) * 2 - 1)
        {
            return 1;
        }
        return 0;
    }
    else if (stackNum == 3)
    {
        if (top3 == MAX - 1)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        printf("Invalid stack number");
        return -1;
    }
}

int main()
{

    while (1)
    {
        int choice;
        printf("\n1. Push \n2. Pop \n3. IsEmpty \n4. IsFull \n5. Exit \nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int stackNum, data;
            printf("Enter stack number: ");
            scanf("%d", &stackNum);
            printf("Enter data: ");
            scanf("%d", &data);
            push(stackNum, data);
        }
        else if (choice == 2)
        {
            int stackNum;
            printf("Enter stack number: ");
            scanf("%d", &stackNum);
            printf("Popped element: %d", pop(stackNum));
        }
        else if (choice == 3)
        {
            int stackNum;
            printf("Enter stack number: ");
            scanf("%d", &stackNum);
            printf("Is empty: %d", isEmpty(stackNum));
        }
        else if (choice == 4)
        {
            int stackNum;
            printf("Enter stack number: ");
            scanf("%d", &stackNum);
            printf("Is full: %d", isFull(stackNum));
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Invalid choice");
        }
    }
}