#include <stdio.h>
#define n 10
int q[n];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (rear == 20)
    {
        printf("waiting for ride");
    }
    rear++;
    q[rear] = data;
}

void dequeue()
{
    if (rear == -1 && front == -1)
        printf("ride empty");
    front++;
}

void display()
{
    if (rear == -1)
        printf("No one up for a ride");
    int i = front;
    while (i <= rear)
    {
        printf("%d", q[i]);

        i++;
    }
}

int main()
{
    int ch;
    int v;
    do
    {
        printf("\n\
        1. Insert\n\
        2. Delete\n\
        3. Dispaly\n\
        4. to Exit\n");
        printf("enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                printf("Enter rider: ");
                scanf("%d", &v);
                enqueue(v);
            }
            printf("wait till the next ride starts...");
            break;
        case 2:
            for (int i = 19; i > 0; i++)
            {
                dequeue();
            }
            printf("Entering the next ride");
            break;
        case 3:
            display();
            break;

        case 4:
            printf("Exiting.....");
            break;
        default:
            printf("enter the correct choice");
        }
    } while (ch != 4);
}