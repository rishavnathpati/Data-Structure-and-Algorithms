#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

/// @brief Enqueue operation on a queue
/// @param d  Data to be inserted
void enqueue(int d) // Insert elements in Queue
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    if ((r == NULL) && (f == NULL))
    {
        f = r = n;
        r->next = f;
    }
    else
    {
        r->next = n;
        r = n;
        n->next = f;
    }
}

/// @brief Dequeue operation on a queue
void dequeue()
{
    struct node *t;
    t = f;
    if ((f == NULL) && (r == NULL))
        printf("\nQueue is Empty");
    else if (f == r)
    {
        f = r = NULL;
        free(t);
    }
    else
    {
        f = f->next;
        r->next = f;
        free(t);
    }
}

/// @brief Display all elements of the queue
void print()
{
    struct node *t;
    t = f;
    if ((f == NULL) && (r == NULL))
        printf("\nQueue is Empty");
    else
    {
        do
        {
            printf("\n%d", t->data);
            t = t->next;
        } while (t != f);
    }
}

/// @brief Main function
/// @return  0 on exit
int main()
{
    int opt, n, i, data;

    do
    {
        printf("\n\
        1. Insert the Data in Queue\n\
        2. Delete the data from the Queue\n\
        3. Show the Data in Queue \n\
        0. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter your data: ");
            scanf("%d", &data);
            enqueue(data);
            i++;
            break;

        case 2:
            dequeue();
            break;
        case 3:

            print();
            break;

        case 0:
            break;

        default:
            printf("\nIncorrect Choice");
        }
    } while (opt != 0);
    return 0;
}