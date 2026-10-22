#include <stdio.h>
#include <conio.h>

#define MAX 50

void main()
{
    float alert[MAX];
    int front = 0, rear = -1;
    int choice, i;

    clrscr();

    do
    {
        printf("\n--- EV Battery Thermal Alert Queue ---");
        printf("\n1. Add Temperature Alert");
        printf("\n2. Process Oldest Alert");
        printf("\n3. View Next Alert");
        printf("\n4. Display All Alerts");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(rear == MAX - 1)
                {
                    printf("\nQueue Overflow!");
                }
                else
                {
                    rear++;
                    printf("\nEnter battery temperature in Celsius: ");
                    scanf("%f", &alert[rear]);

                    printf("\nAlert added successfully.");

                    if(alert[rear] >= 60)
                        printf("\nWARNING: Critical battery temperature!");
                    else if(alert[rear] >= 45)
                        printf("\nALERT: High battery temperature.");
                }
                break;

            case 2:
                if(front > rear)
                {
                    printf("\nNo alerts to process.");
                }
                else
                {
                    printf("\nProcessing alert: %.2f C", alert[front]);
                    front++;

                    if(front > rear)
                    {
                        front = 0;
                        rear = -1;
                    }
                }
                break;

            case 3:
                if(front > rear)
                {
                    printf("\nNo alerts available.");
                }
                else
                {
                    printf("\nNext alert: %.2f C", alert[front]);
                }
                break;

            case 4:
                if(front > rear)
                {
                    printf("\nNo alerts available.");
                }
                else
                {
                    printf("\nPending alerts:");

                    for(i = front; i <= rear; i++)
                    {
                        printf("\n%.2f C", alert[i]);
                    }
                }
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
