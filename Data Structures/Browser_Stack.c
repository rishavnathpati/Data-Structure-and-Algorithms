// To facilitate a thorough net surfing, any web browser has back and forward
// buttons that allow the user to move backward and forward through a series
// of web pages. The browser keeps track of the pages that have been visited
// and the order in which they were visited. The browser also keeps track of
// the pages that have been visited after the current page. When the user
// presses the back button, the browser displays the previous page in the
// history list. When the user presses the forward button, the browser
// displays the next page in the history list. If there is no next page, the
// forward button is disabled. If there is no previous page, the back button
// is disabled. Write a program that simulates a browser. The program should
// use a stack to store the pages that have been visited. When the user
// visits a new page, the program should push the page onto the stack. When
// the user presses the back button, the program should pop the top page
// from the stack and display it. When the user presses the forward button,
// the program should push the current page onto the stack and display the
// next page in the stack. Use the following menu of choices:
// 1. Visit a new page
// 2. Back
// 3. Forward
// 4. Quit
// The program should display an error message if the user presses the back
// button when there are no pages in the back history list, or if the user
// presses the forward button when there are no pages in the forward history
// list. The program should also display an error message if the user tries
// to visit a new page while there are pages in the forward history list.
// The program should display an error message if the user tries to quit
// without first visiting a new page or pressing the back button to return
// to a previously visited page. Array implementation of stack is used here.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack using array

typedef struct stack
{
    char *arr[MAX];
    int top;
} stack;

void init(stack *s)
{
    s->top = -1;
}

int is_empty(stack *s)
{
    return s->top == -1;
}

int is_full(stack *s)
{
    return s->top == MAX - 1;
}

void push(stack *s, char *str)
{
    if (is_full(s))
    {
        printf("Stack overflow");
        exit(1);
    }
    s->arr[++s->top] = str;

}

char *pop(stack *s)
{
    if (is_empty(s))
    {
        printf("Stack underflow");
        exit(1);
    }
    return s->arr[s->top--];
}

char *peek(stack *s)
{
    if (is_empty(s))
    {
        printf("Stack underflow");
        exit(1);
    }
    return s->arr[s->top];
}

void display(stack *s)
{
    if (is_empty(s))
    {
        printf("Stack underflow");
        exit(1);
    }
    for (int i = s->top; i >= 0; i--)
    {
        printf("%s ", s->arr[i]);
    }
    printf("    ");

}

int main()
{
    stack s;
    init(&s);
    int choice;
    char *str;
    while (1)
    {
        printf("\
\n1. Visit a new page\
\n2. Back\
\n3. Forward\
\n4. Quit");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                if (!is_empty(&s))
                {
                    printf("Error: You must go back to visit a new page");
                    exit(1);
                }
                printf("Enter the page name: ");
                scanf("%s", str);
                push(&s, str);
                break;
            case 2:
                if (is_empty(&s))
                {
                    printf("Error: No pages in back history list");
                    exit(1);
                }
                printf("You are visiting %s", peek(&s));
                break;
            case 3:
                if (is_empty(&s))
                {
                    printf("Error: No pages in forward history list");
                    exit(1);
                }
                printf("You are visiting %s", pop(&s));
                break;
            case 4:
                if (!is_empty(&s))
                {
                    printf("Error: You must go back to quit");
                    exit(1);
                }
                exit(0);
            default:
                printf("Invalid choice");
                exit(1);
        }
    }
    return 0;
}
