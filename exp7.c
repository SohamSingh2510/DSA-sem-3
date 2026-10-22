#include <stdio.h>
#include <conio.h>

#define MAX 10

int a[MAX][MAX], visited[MAX];
int q[MAX], front, rear, n;

void bfs(int start)
{
    int i, v;

    for(i = 0; i < n; i++)
        visited[i] = 0;

    front = rear = 0;
    q[rear] = start;
    visited[start] = 1;

    while(front <= rear)
    {
        v = q[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(a[v][i] == 1 && !visited[i])
            {
                q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void main()
{
    int ch, i, j, start;

    clrscr();

    do
    {
        printf("\n1.Create Graph and Traverse");
        printf("\n2.Exit\nChoice: ");
        scanf("%d", &ch);

        if(ch == 1)
        {
            printf("Enter number of cities (max 10): ");
            scanf("%d", &n);

            if(n < 1 || n > MAX)
            {
                printf("\nInvalid number of cities");
                continue;
            }

            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                {
                    if(i == j)
                        a[i][j] = 0;
                    else
                    {
                        printf("Connection between %d and %d (0/1): ",
                               i, j);
                        scanf("%d", &a[i][j]);
                    }
                }

            printf("Enter starting city (0 to %d): ", n-1);
            scanf("%d", &start);

            if(start >= 0 && start < n)
            {
                printf("BFS traversal: ");
                bfs(start);
            }
            else
                printf("\nInvalid starting city");
        }
    } while(ch != 2);

    getch();
}
