#include <stdio.h>
#define MAX 10

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

/// @brief Insert an element into circular queue
/// @param item  Element to be inserted
void insert(int item)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (front == -1) /*If queue is empty */
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX - 1) /*rear is at last position of queue */
            rear = 0;
        else
            rear = rear + 1;
    }
    cqueue_arr[rear] = item;
}

/// @brief Delete an element from Circular Queue
void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", cqueue_arr[front]);
    if (front == rear) /* queue has only one element */
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
}

/// @brief Display all elements of the queue
void display()
{
    int front_pos = front, rear_pos = rear;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (front_pos <= rear_pos)
        while (front_pos <= rear_pos)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
    else
    {
        while (front_pos <= MAX - 1)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

/// @brief Main function
/// @return 0 on success
int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Input the element for insertion in queue : ");
            scanf("%d", &item);

            insert(item);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong choice\n");
        }
    }

    return 0;
}
