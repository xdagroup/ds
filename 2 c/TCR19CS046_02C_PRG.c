#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void enq(int);
void deq(int);
void check(int);
void show();

int queue[MAX];
int front = -1, rear = -1;
void main()
{
    int num, op;
    printf("\nMENU");
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Print");
    printf("\n4.Exit");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the value to be inserted: ");
            scanf("%d", &num);
            enq(num);
            break;
        case 2:
            printf("\nEnter the value to be deleted : ");
            scanf("%d", &num);
            deq(num);
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid!!!");
        }
    }
}

void enq(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow!!!");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        queue[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}

void check(int elements)
{
    int i, j;
    for (i = 0; i <= rear; i++)
    {
        if (elements >= queue[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                queue[j] = queue[j - 1];
            }
            queue[i] = elements;
            return;
        }
    }
    queue[i] = elements;
}

void deq(int elements)
{
    int i;
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
    for (i = 0; i <= rear; i++)
    {
        if (elements == queue[i])
        {
            for (; i < rear; i++)
            {
                queue[i] = queue[i + 1];
            }
            queue[i] = -99;
            rear--;
            if (rear == -1)
                front = -1;
            return;
        }
    }
    printf("\n%d not found!!", elements);
}

void show()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
    for (; front <= rear; front++)
    {
        printf(" %d ", queue[front]);
    }
    front = 0;
}