#include <stdio.h>
#include <conio.h>

#define MAX 50

void main()
{
    int a[MAX], n, ch, i, j, temp;

    clrscr();

    do
    {
        printf("\n1.Enter Marks and Sort");
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

            for(i = 0; i < n; i++)
            {
                printf("Enter marks of student %d: ", i+1);
                scanf("%d", &a[i]);
            }

            for(i = 0; i < n-1; i++)
            {
                for(j = 0; j < n-i-1; j++)
                {
                    if(a[j] > a[j+1])
                    {
                        temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                    }
                }
            }

            printf("\nMarks in ascending order:\n");

            for(i = 0; i < n; i++)
                printf("%d ", a[i]);
        }
    } while(ch != 2);

    getch();
}
