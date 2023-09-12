#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

char stack[SIZE];
int top = -1, i = 0, status = 1;

void push(char exp);
int checkBracket(char exp);
int checkBalanced(char exp);

int main()
{
    char exp[SIZE];

    printf("enter expression:");
    scanf("%[^\n]s", exp);

    while (exp[i] != '\0')
    {

        if (checkBracket(exp[i]) != 0)
        {

            if (checkBracket(exp[i]) == 1)
            {
                push(exp[i]);
            }
            else if (!checkBalanced(exp[i]))
            {
                status = 0;
                break;
            }
        }
        i++;
    }
    printf((status && top == -1) ? "balanced" : "unbalanced");
}

void push(char exp)
{
    if (top == SIZE - 1)
    {
        printf("stack overflow!");
        exit(1);
    }
    stack[++top] = exp;
}

int checkBalanced(char exp)
{
    char a;
    if (top == -1)
    {
        return 0;
    }
    switch (exp)
    {
    case ')':
        a = '(';
        break;
    case ']':
        a = '[';
        break;
    case '}':
        a = '{';
        break;
    }
    return (a == stack[top--]);
}

int checkBracket(char val)
{
    switch (val)
    {
    case '(':
    case '[':
    case '{':
        return 1;
    case '}':
    case ']':
    case ')':
        return 2;
    default:
        return 0;
    }
}
