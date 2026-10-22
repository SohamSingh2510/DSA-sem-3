#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int roll;
    struct node *left, *right;
};

struct node *root = NULL;

struct node *insert(struct node *p, int x)
{
    if(p == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->roll = x;
        p->left = p->right = NULL;
    }
    else if(x < p->roll)
        p->left = insert(p->left, x);
    else if(x > p->roll)
        p->right = insert(p->right, x);

    return p;
}

void inorder(struct node *p)
{
    if(p != NULL)
    {
        inorder(p->left);
        printf("%d ", p->roll);
        inorder(p->right);
    }
}

void preorder(struct node *p)
{
    if(p != NULL)
    {
        printf("%d ", p->roll);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(struct node *p)
{
    if(p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->roll);
    }
}

void main()
{
    int ch, x;

    clrscr();

    do
    {
        printf("\n\n1.Insert Roll Number");
        printf("\n2.Inorder Traversal");
        printf("\n3.Preorder Traversal");
        printf("\n4.Postorder Traversal");
        printf("\n5.Exit\nChoice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                inorder(root);
                break;

            case 3:
                preorder(root);
                break;

            case 4:
                postorder(root);
                break;

            case 5:
                break;

            default:
                printf("\nInvalid choice");
        }
    } while(ch != 5);

    getch();
}
