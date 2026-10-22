#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

int priority(char c)
{
    if(c == '^') return 3;
    if(c == '*' || c == '/' || c == '%') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

void main()
{
    char infix[100], postfix[100], c;
    int ch, i, j;

    clrscr();

    do
    {
        printf("\n1.Convert Infix to Postfix");
        printf("\n2.Exit\nChoice: ");
        scanf("%d", &ch);

        if(ch == 1)
        {
            top = -1;
            printf("Enter infix expression: ");
            scanf("%99s", infix);
            j = 0;

            for(i = 0; infix[i] != '\0'; i++)
            {
                c = infix[i];

                if(isalnum(c))
                    postfix[j++] = c;
                else if(c == '(')
                    stack[++top] = c;
                else if(c == ')')
                {
                    while(top >= 0 && stack[top] != '(')
                        postfix[j++] = stack[top--];

                    if(top >= 0)
                        top--;
                }
                else
                {
                    while(top >= 0 && stack[top] != '(' &&
                         (priority(stack[top]) > priority(c) ||
                         (priority(stack[top]) == priority(c) && c != '^')))
                        postfix[j++] = stack[top--];

                    stack[++top] = c;
                }
            }

            while(top >= 0)
                postfix[j++] = stack[top--];

            postfix[j] = '\0';
            printf("Postfix expression: %s", postfix);
        }
    } while(ch != 2);

    getch();
}
