// Develop a program to merge two Linked List and remove the duplicated in it.
// The linked can be chosen as Singly Linked List or Doubly Linked List as per your choice.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(struct node *head)
{
    struct node *newnode, *temp;
    int n, i;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL)
            printf(" -> ");
    }
    printf(" ");
}

void removeDuplicates(struct node *head)
{
    struct node *temp1, *temp2, *temp3;
    temp1 = head;
    while (temp1 != NULL && temp1->next != NULL)
    {
        temp2 = temp1;
        while (temp2->next != NULL)
        {
            if (temp1->data == temp2->next->data)
            {
                temp3 = temp2->next;
                temp2->next = temp2->next->next;
                free(temp3);
            }
            else
                temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

struct node *merge(struct node *head1, struct node *head2)
{
    struct node *head3, *temp1, *temp2, *temp3, *newnode;
    temp1 = head1;
    temp2 = head2;
    head3 = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (temp1->data < temp2->data)
        {
            newnode->data = temp1->data;
            temp1 = temp1->next;
        }
        else if (temp1->data > temp2->data)
        {
            newnode->data = temp2->data;
            temp2 = temp2->next;
        }
        else
        {
            newnode->data = temp1->data;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        newnode->next = NULL;
        if (head3 == NULL)
        {
            head3 = newnode;
            temp3 = newnode;
        }
        else
        {
            temp3->next = newnode;
            temp3 = newnode;
        }
    }
    while (temp1 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = temp1->data;
        newnode->next = NULL;
        temp3->next = newnode;
        temp3 = newnode;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = temp2->data;
        newnode->next = NULL;
        temp3->next = newnode;
        temp3 = newnode;
        temp2 = temp2->next;
    }
    removeDuplicates(head3);
    return head3;
}

int main()
{
    struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    head1 = create(head1);
    head2 = create(head2);

    printf("\nFirst Linked List: ");
    display(head1);

    printf("\nSecond Linked List: ");
    display(head2);

    head3 = merge(head1, head2);
    printf("\nMerged Linked List: ");
    display(head3);

    return 0;
}
