#include <stdio.h>
#include <conio.h>

#define MAX 50

void main()
{
    int a[MAX], n, ch, i, key;
    int low, high, mid, found;

    clrscr();

    do
    {
        printf("\n1.Enter Sorted Roll Numbers and Search");
        printf("\n2.Exit\nChoice: ");
        scanf("%d", &ch);

        if(ch == 1)
        {
            printf("Enter number of students (max 50): ");
            scanf("%d", &n);

            if(n < 1 || n > MAX)
            {
                printf("\nInvalid number");
                continue;
            }

            printf("Enter roll numbers in ascending order:\n");

            for(i = 0; i < n; i++)
                scanf("%d", &a[i]);

            printf("Enter roll number to search: ");
            scanf("%d", &key);

            low = 0;
            high = n-1;
            found = 0;

            while(low <= high)
            {
                mid = low + (high-low)/2;

                if(a[mid] == key)
                {
                    found = 1;
                    break;
                }
                else if(a[mid] < key)
                    low = mid+1;
                else
                    high = mid-1;
            }

            if(found)
                printf("\nRoll number found at position %d", mid+1);
            else
                printf("\nRoll number not found");
        }
    } while(ch != 2);

    getch();
}
