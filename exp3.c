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
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("\nMemory allocation failed.");
        return;
    }

    printf("\nEnter sensor ID: ");
    scanf("%d", &newnode->id);

    printf("Enter battery temperature in Celsius: ");
    scanf("%f", &newnode->temp);

    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("\nSensor reading added successfully.");

    if(newnode->temp >= 60)
        printf("\nWARNING: Critical battery temperature!");
    else if(newnode->temp >= 45)
        printf("\nALERT: High battery temperature.");
}

void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("\nNo sensor readings available.");
        return;
    }

    temp = head;

    printf("\n--- Battery Sensor Readings ---");

    while(temp != NULL)
    {
        printf("\nSensor ID: %d", temp->id);
        printf("\nTemperature: %.2f C", temp->temp);
        printf("\n");

        temp = temp->next;
    }
}

void search()
{
    struct node *temp;
    int id, found = 0;

    printf("\nEnter sensor ID to search: ");
    scanf("%d", &id);

    temp = head;

    while(temp != NULL)
    {
        if(temp->id == id)
        {
            printf("\nSensor ID: %d", temp->id);
            printf("\nTemperature: %.2f C", temp->temp);
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if(found == 0)
    {
        printf("\nSensor not found.");
    }
}

void delete()
{
    struct node *temp, *prev;
    int id;

    if(head == NULL)
    {
        printf("\nNo sensor readings available.");
        return;
    }

    printf("\nEnter sensor ID to delete: ");
    scanf("%d", &id);

    temp = head;
    prev = NULL;

    while(temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("\nSensor not found.");
        return;
    }

    if(prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("\nSensor reading deleted successfully.");
}

void main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n--- EV Battery Sensor Monitoring ---");
        printf("\n1. Add Sensor Reading");
        printf("\n2. Display All Readings");
        printf("\n3. Search Sensor");
        printf("\n4. Delete Sensor Reading");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                delete();
                break;

            case 5:
                printf("\nExiting program.");
                break;

            default:
                printf("\nInvalid choice.");
        }

    } while(choice != 5);

    getch();
}
