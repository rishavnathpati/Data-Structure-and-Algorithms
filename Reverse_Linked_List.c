// Write a program to print the traversal of a reverse linked List using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_beg(int);
void insert_end(int);
void traverse();
void reverse();

int main()
{
    printf("\033[H\033[J");
    int choice, value;
    while (1)
    {
        printf("\n********* LINKED LIST MENU *********\n");
        printf("1. Insert Element at the beginning of the Linked List\n");
        printf("2. Insert Element at the end of the Linked List\n");
        printf("3. Traverse the Linked List\n");
        printf("4. Reverse the Linked List\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);

        //Clear the input buffer
        printf("\033[H\033[J");
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            insert_beg(value);
            break;

        case 2:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            insert_end(value);
            break;

        case 3:
            traverse();
            break;

        case 4:
            reverse();
            break;

        case 0:
            printf("Exiting from the program\n");
            exit(0);
            break;
        }
    }
}

void insert_beg(int value)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

void insert_end(int value)
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void traverse()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

//Inverse linked list
void reverse()
{
    struct node *prev, *current, *next;
    prev = NULL;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
