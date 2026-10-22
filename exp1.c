#include <stdio.h>
#include <conio.h>

#define MAX 50

void main()
{
    float temp[MAX];
    int top = -1, choice, i;

    clrscr();

    do
    {
        printf("\n--- EV Battery Thermal Monitoring ---");
        printf("\n1. Record Temperature");
        printf("\n2. Remove Latest Reading");
        printf("\n3. View Latest Reading");
        printf("\n4. Display All Readings");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(top == MAX - 1)
                {
                    printf("\nStack Overflow!");
                }
                else
                {
                    top++;
                    printf("\nEnter battery temperature in Celsius: ");
                    scanf("%f", &temp[top]);

                    printf("\nTemperature recorded successfully.");

                    if(temp[top] >= 60)
                        printf("\nWARNING: Critical battery temperature!");
                    else if(temp[top] >= 45)
                        printf("\nALERT: Battery temperature is high.");
                }
                break;

            case 2:
                if(top == -1)
                {
                    printf("\nNo readings available.");
                }
                else
                {
                    printf("\nRemoved temperature: %.2f C", temp[top]);
                    top--;
                }
                break;

            case 3:
                if(top == -1)
                {
                    printf("\nNo readings available.");
                }
                else
                {
                    printf("\nLatest temperature: %.2f C", temp[top]);
                }
                break;

            case 4:
                if(top == -1)
                {
                    printf("\nNo readings available.");
                }
                else
                {
                    printf("\nTemperature readings (latest first):");

                    for(i = top; i >= 0; i--)
                    {
                        printf("\n%.2f C", temp[i]);
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
