// Stack program in c

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
        printf("Not a valid position for the stack");
        return -1;
    }
    else
    {
        return ptr->arr[arrayInd];
    }
}

display(struct stack *ptr)
{
    for (int i = ptr->top; i >= 0; i--)
    {
        printf("Element %d", ptr->arr[i]);
    }
}


int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack has been created successfully");
    while( 1){
        printf("\n1. Push 2. Pop 3. Display 4. Peek 5. Exit");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be pushed");
            int val;
            scanf("%d", &val);
            push(s, val);
            break;

        case 2:
            printf("\nThe value popped is %d", pop(s));
            break;

        case 3:
            display(s);
            break;

        case 4:
            printf("Enter the position to be peeked");
            int pos;
            scanf("%d", &pos);
            printf("The value at position %d is %d", pos, peek(s, pos));
            break;

        case 5:
            exit(0);
            break;
        }

    }
    return 0;
}

