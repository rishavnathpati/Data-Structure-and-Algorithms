// Implement a program to perform the Polynomial Addition using Singly Liked List.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *create(struct node *head)
{
    struct node *newnode, *temp;
    int n, i;
    printf("\nEnter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the %d coefficient: ", i);
        scanf("%d", &newnode->coeff);
        printf("Enter the %d exponent: ", i);
        scanf("%d", &newnode->exp);
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
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("");
}

struct node *add(struct node *head1, struct node *head2)
{
    struct node *head3, *temp1, *temp2, *temp3, *newnode;
    temp1 = head1;
    temp2 = head2;
    head3 = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        if (temp1->exp == temp2->exp)
        {
            newnode->coeff = temp1->coeff + temp2->coeff;
            newnode->exp = temp1->exp;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            newnode->coeff = temp1->coeff;
            newnode->exp = temp1->exp;
            temp1 = temp1->next;
        }
        else
        {
            newnode->coeff = temp2->coeff;
            newnode->exp = temp2->exp;
            temp2 = temp2->next;
        }
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
        newnode->coeff = temp1->coeff;
        newnode->exp = temp1->exp;
        newnode->next = NULL;
        temp3->next = newnode;
        temp3 = newnode;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->coeff = temp2->coeff;
        newnode->exp = temp2->exp;
        newnode->next = NULL;
        temp3->next = newnode;
        temp3 = newnode;
        temp2 = temp2->next;
    }
    return head3;
}

int main()
{
    struct node *head1, *head2, *head3;
    head1 = NULL;
    head2 = NULL;
    head3 = NULL;
    printf("\nEnter the first polynomial: ");
    head1 = create(head1);
    printf("\nEnter the second polynomial: ");
    head2 = create(head2);
    printf("\nFirst polynomial: ");
    display(head1);
    printf("\nSecond polynomial: ");
    display(head2);
    head3 = add(head1, head2);
    printf("\nResultant polynomial: ");
    display(head3);
    return 0;
}
