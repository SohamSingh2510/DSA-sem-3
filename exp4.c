#include <stdio.h>
#include <conio.h>
#define MAX 5

int q[MAX];
int front = -1, rear = -1;

void insertFront()
{
    int x;

    if((front == 0 && rear == MAX-1) ||
       front == rear+1)
    {
        printf("\nDeque Full");
        return;
    }

    printf("Enter task ID: ");
    scanf("%d", &x);

    if(front == -1)
        front = rear = 0;
    else if(front == 0)
        front = MAX-1;
    else
        front--;

    q[front] = x;
}

void insertRear()
{
    int x;

    if((front == 0 && rear == MAX-1) ||
       front == rear+1)
    {
        printf("\nDeque Full");
        return;
    }

    printf("Enter task ID: ");
    scanf("%d", &x);

    if(front == -1)
        front = rear = 0;
    else if(rear == MAX-1)
        rear = 0;
    else
        rear++;

    q[rear] = x;
}

void deleteFront()
{
    if(front == -1)
        printf("\nDeque Empty");
    else
    {
        printf("\nDeleted task: %d", q[front]);

        if(front == rear)
            front = rear = -1;
        else if(front == MAX-1)
            front = 0;
        else
            front++;
    }
}

void deleteRear()
{
    if(rear == -1)
        printf("\nDeque Empty");
    else
    {
        printf("\nDeleted task: %d", q[rear]);

        if(front == rear)
            front = rear = -1;
        else if(rear == 0)
            rear = MAX-1;
        else
            rear--;
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("\nDeque Empty");
        return;
    }

    i = front;

    while(1)
    {
        printf("%d ", q[i]);

        if(i == rear)
            break;

        i = (i+1) % MAX;
    }
}

void main()
{
    int ch;

    clrscr();

    do
    {
        printf("\n\n1.Insert Front\n2.Insert Rear");
        printf("\n3.Delete Front\n4.Delete Rear");
        printf("\n5.Display Tasks\n6.Exit\nChoice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insertFront(); break;
            case 2: insertRear(); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 6: break;
            default: printf("\nInvalid choice");
        }
    } while(ch != 6);

    getch();
}
