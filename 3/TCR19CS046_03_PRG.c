#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char infix[20], postfix[20];
int tos;
int stack[20];

int pop();
int precedence(char symbol);
int isEmpty();
void infix_to_postfix();
int check_space(char symbol);
void push(int symbol);
void infix_to_postfix()
{
    unsigned int count, temp = 0;
    char next;
    char ch;
    for (count = 0; count < strlen(infix); count++)
    {
        ch = infix[count];
        if (!check_space(ch))
        {
            switch (ch)
            {
            case '(':
                push(ch);
                break;
            case ')':
                while ((next = pop()) != '(')
                {
                    postfix[temp++] = next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while (!isEmpty() && precedence(stack[tos]) >= precedence(ch))
                    postfix[temp++] = pop();
                push(ch);
                break;
            default:
                postfix[temp++] = ch;
            }
        }
    }
    while (!isEmpty())
    {
        postfix[temp++] = pop();
    }
    postfix[temp] = '\0';
}
int precedence(char ch)
{
    switch (ch)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int check_space(char ch)
{
    if (ch == '\t' || ch == ' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int ch)
{
    if (tos > 20)
    {
        printf("Stack Overflow!!!\n");
        exit(1);
    }
    tos = tos + 1;
    stack[tos] = ch;
}

int isEmpty()
{
    if (tos == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow!!!\n");
        exit(1);
    }
    return (stack[tos--]);
}

int main()
{
    int count, len;
    char temp;
    tos = -1;
    printf("\nEnter the infix expression : ");
    scanf("%s", infix);
    infix_to_postfix();
    printf("\nThe postfix expression is %s\n", postfix);
    return 0;
}
