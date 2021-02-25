#include<stdio.h>
#include<stdlib.h>

#define size 10

struct node
{
    int data;
    struct node *next;
};

struct node *ch[size];

void start()
{
    int i;
    for(i = 0; i < size; i++)
        ch[i] = NULL;
}

void insert(int value)
{
    
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;


    int key = value % size;

    if(ch[key] == NULL)
        ch[key] = newNode;

    else
    {

        struct node *temp = ch[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = ch[i];
        printf("CHAIN[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("Null!!!\n");
    }
}

int main()
{

    start();

    insert(10);
    insert(1);
    insert(11);
    insert(15);
    insert(45);
    insert(22);

    print();

    return 0;
}