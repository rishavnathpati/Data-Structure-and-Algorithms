// Create a program that provides a binary converter by using stack. 
// Use stack to store the remainder. 
// The program would get as input a decimal number and would output the binary equivalent.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];

int top = -1;

void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack is full");
        return;
    }
    stack[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty");
        return -1;
    }
    return stack[top--];
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    while (num != 0)
    {
        push(num % 2);
        num /= 2;
    }
    while (top != -1)
    {
        printf("%d", pop());
    }
    return 0;
}