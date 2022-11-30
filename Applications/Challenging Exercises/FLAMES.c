// Assume FLAMES game that tests for relationship has to be implemented using a dynamic structure. 
// The letters in the FLAMES stand for Friends, Love, Affection, Marriage, Enmity and Sister. 
// Initially store the individual letters of the word ‘flames’ in the nodes of the dynamic structure. 
// Given the count of the number of uncommon letters in the two names ‘n’, write a program to delete every nth node in it, till it is left with a single node. 
// If the end of the dynamic structure is reached while counting, resume the counting from the beginning. 
// Display the letter that still remains and the corresponding relationship.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
};

struct node *head = NULL;

void insert(char data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void display()
{
    struct node *temp = head;
    while (temp->next != head)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("%c ", temp->data);
}

void deleteNode(int n)
{
    struct node *temp = head;
    struct node *prev = NULL;
    int count = 1;
    while (temp->next != temp)
    {
        if (count == n)
        {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
            count = 1;
        }
        else
        {
            prev = temp;
            temp = temp->next;
            count++;
        }
    }
    head = temp;
}

int main()
{
    char flames[] = "flames";
    for (int i = 0; i < strlen(flames); i++)
    {
        insert(flames[i]);
    }

    printf("The letters in the word flames are: ");
    display();

    int n;

    printf("\nEnter the first name: ");
    char name1[100];
    scanf("%s", name1);

    printf("\nEnter the second name: ");
    char name2[100];
    scanf("%s", name2);

    int count = 0;
    for (int i = 0; i < strlen(name1); i++)
    {
        for (int j = 0; j < strlen(name2); j++)
        {
            if (name1[i] == name2[j])
            {
                name1[i] = ' ';
                name2[j] = ' ';
                count++;
                break;
            }
        }
    }

    n = strlen(name1) + strlen(name2) - 2 * count;
    deleteNode(n);
    printf("The relationship is: ");
    display();
    return 0;
}