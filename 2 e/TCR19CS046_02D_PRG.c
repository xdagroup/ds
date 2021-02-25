#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int front;
    int rear;
    int size;
    int *p;
};

void create(struct CircularQueue *x, int size)
{
    x->size = size;
    x->front = x->rear = 0;
    x->p = (int *)malloc(x->size * sizeof(int));
}
void enq(struct CircularQueue *q, int x)
{

    if ((q->rear + 1) % q->size == q->front)
        printf("Queue Overflow!!!\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->p[q->rear] = x;
    }
}

void deq(struct CircularQueue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Queue Underflow!!!");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->p[q->front];
        printf("Deleted Element=%d", x);
        printf("\n");
    }
}

void show(struct CircularQueue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d", q.p[i]);
        i = (i + 1) % q.size;
        printf("\t");
    } while (i != (q.rear + 1) % q.size);

    printf("\n");
}
void main()
{
    struct CircularQueue q;
    create(&q, 10);
    enq(&q, 8);
    enq(&q, 9);
    enq(&q, 10);
    show(q);
    deq(&q);
    show(q);
}