// Write a program to create a Singly Linked List using dynamic memory allocation. If Linked list is empty then display “Linked List is Empty” otherwise display the elements of Linked List.
// Hint:
// Insert Element at the beginning of the Linked List
// Insert Element at the end of the Linked List
// Traverse the Linked List
// Delete Element from the beginning
// Delete Element from the end
// Exit

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
void delete_beg();
void delete_end();

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
        printf("4. Delete Element from the beginning\n");
        printf("5. Delete Element from the end\n");
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
            delete_beg();
            break;
        case 5:
            delete_end();
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice");
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
        printf("Linked List is Empty");
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

void delete_beg()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Linked List is Empty");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_end()
{
    struct node *temp, *prev;
    if (head == NULL)
    {
        printf("Linked List is Empty");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}