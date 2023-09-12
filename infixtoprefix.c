#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

char stack[SIZE];
char prefix[SIZE];
int top = -1, pretop = -1;

void push(char opr);
void pop();
int precedence(char opr);

void main()
{

    char exp[100];
    printf("enter the expression:");
    scanf("%s", exp);

    int i = strlen(exp) - 1;

    while (i >= 0)
    {
        if (isalnum(exp[i]))
        {
            prefix[++pretop] = exp[i];
        }
        else if (exp[i] == ')')
        {
            push(exp[i]);
        }
        else if (exp[i] == '(')
        {
            while (stack[top] != ')')
            {
                pop();
            }
            top--;
        }
        else
        {
            while (precedence(stack[top]) > precedence(exp[i]))
            {
                pop();
            }
            push(exp[i]);
        }
        i--;
    }

    while (top != -1)
    {
        pop();
    }

    printf("%s", strrev(prefix));
}

void push(char opr)
{
    if (top == SIZE - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        stack[++top] = opr;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("stack is empty");
        exit(1);
    }
    else
    {
        prefix[++pretop] = stack[top--];
    }
}

int precedence(char opr)
{
    switch (opr)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
    default:
        return 0;
    }
}