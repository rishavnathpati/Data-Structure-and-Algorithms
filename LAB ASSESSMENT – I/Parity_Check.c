// Develop a program to find the parity is EVEN PARITY or ODD
// PARITY of the given ERROR DETECTION CODE given as the input
// string. The given input string contains only the binary digits (bits) either
// 0 or 1. Assume the input string is of the half word length i.e. 16 bits and
// the last bit is allocated to assign the parity. Use stack to find the parity
// of the given input string.
// Input: 1010101010101010
// Output: EVEN PARITY
// Input: 1010101010101011
// Output: ODD PARITY

#include <stdio.h>
#include <stdlib.h>

// create a stack program

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack ", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    int arrayInd = ptr->top - i + 1;
    if (arrayInd < 0)
    {
        // printf("Not a valid position for the stack ");
        return -1;
    }
    else
    {
        return ptr->arr[arrayInd];
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 16;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    char str[17];
    printf("Enter the 16 bit binary string: ");
    scanf("%s", str);

    for (int i = 0; i < 16; i++)
    {
        if (str[i] == '1' && peek(s, 1) != 1)
        {
            push(s, 1);
        }
        else if (str[i] == '1' && peek(s, 1) == 1)
        {
            pop(s);
        }

        printf("\nStack after %d iteration is: %d", i + 1, peek(s, 1));
    }

    if (peek(s, 1)!=1)
    {
        printf("\nEVEN PARITY");
    }
    else
    {
        printf("\nODD PARITY");
    }

    return 0;
}
