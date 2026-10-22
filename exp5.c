#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int id;
    float temp;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
    struct node *n, *p;

    n = (struct node *)malloc(sizeof(struct node));

    if(n == NULL)
    {
        printf("\nMemory allocation failed");
        return;
    }

    printf("Enter sensor ID: ");
    scanf("%d", &n->id);
    printf("Enter temperature: ");
    scanf("%f", &n->temp);

    n->next = NULL;

    if(head == NULL)
        head = n;
    else
    {
        p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = n;
    }

    if(n->temp >= 60)
        printf("\nCritical temperature alert!");
    else if(n->temp >= 45)
        printf("\nHigh temperature alert!");

    printf("\nReading added");
}

void display()
{
    struct node *p = head;

    if(p == NULL)
        printf("\nNo readings available");

    while(p != NULL)
    {
        printf("\nSensor ID: %d  Temperature: %.2f C",
               p->id, p->temp);
        p = p->next;
    }
}

void search()
{
    struct node *p = head;
    int id;

    printf("Enter sensor ID: ");
    scanf("%d", &id);

    while(p != NULL)
    {
        if(p->id == id)
        {
            printf("\nTemperature: %.2f C", p->temp);
            return;
        }
        p = p->next;
    }

    printf("\nSensor not found");
}

void deleteNode()
{
    struct node *p = head, *prev = NULL;
    int id;

    printf("Enter sensor ID to delete: ");
    scanf("%d", &id);

    while(p != NULL && p->id != id)
    {
        prev = p;
        p = p->next;
    }

    if(p == NULL)
    {
        printf("\nSensor not found");
        return;
    }

    if(prev == NULL)
        head = p->next;
    else
        prev->next = p->next;

    free(p);
    printf("\nReading deleted");
}

void update()
{
    struct node *p = head;
    int id;

    printf("Enter sensor ID: ");
    scanf("%d", &id);

    while(p != NULL)
    {
        if(p->id == id)
        {
            printf("Enter new temperature: ");
            scanf("%f", &p->temp);

            if(p->temp >= 60)
                printf("\nCritical temperature alert!");
            else if(p->temp >= 45)
                printf("\nHigh temperature alert!");

            printf("\nReading updated");
            return;
        }
        p = p->next;
    }

    printf("\nSensor not found");
}

void main()
{
    int ch;

    clrscr();

    do
    {
        printf("\n\n--- EV Battery Monitoring ---");
        printf("\n1.Add Reading\n2.Display Readings");
        printf("\n3.Search Sensor\n4.Delete Reading");
        printf("\n5.Update Reading\n6.Exit\nChoice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: deleteNode(); break;
            case 5: update(); break;
            case 6: break;
            default: printf("\nInvalid choice");
        }
    } while(ch != 6);

    getch();
}
