// Write a program for Binary Search Tree to implement following operations:
// a. Insertion
// b. Deletion i. Delete node with only child ii. Delete node with both children
// c. Finding an element
// d. Finding Min element
// e. Finding Max element
// f. Left child of the given node
// g. Right child of the given node
// h. Finding the number of nodes, leaves nodes, full nodes, ancestors, descendants.

// Path: LAB ASSESSMENT – I/Binary_Search_Tree.c

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        struct node *temp = root;
        while (1)
        {
            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

void display(struct node *temp)
{
    if (temp != NULL)
    {
        display(temp->left);
        printf("%d ", temp->data);
        display(temp->right);
    }
}

void deleteNode(int data)
{
    struct node *temp = root;
    struct node *prev = NULL;
    while (temp != NULL)
    {
        if (data == temp->data)
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                if (prev->left == temp)
                {
                    prev->left = NULL;
                }
                else
                {
                    prev->right = NULL;
                }
                free(temp);
                break;
            }
            else if (temp->left == NULL || temp->right == NULL)
            {
                if (prev->left == temp)
                {
                    if (temp->left == NULL)
                    {
                        prev->left = temp->right;
                    }
                    else
                    {
                        prev->left = temp->left;
                    }
                }
                else
                {
                    if (temp->left == NULL)
                    {
                        prev->right = temp->right;
                    }
                    else
                    {
                        prev->right = temp->left;
                    }
                }
                free(temp);
                break;
            }
            else
            {
                struct node *temp2 = temp->right;
                struct node *prev2 = temp;
                while (temp2->left != NULL)
                {
                    prev2 = temp2;
                    temp2 = temp2->left;
                }
                temp->data = temp2->data;
                if (prev2->left == temp2)
                {
                    prev2->left = temp2->right;
                }
                else
                {
                    prev2->right = temp2->right;
                }
                free(temp2);
                break;
            }
        }
        else if (data < temp->data)
        {
            prev = temp;
            temp = temp->left;
        }
        else
        {
            prev = temp;
            temp = temp->right;
        }
    }
}



