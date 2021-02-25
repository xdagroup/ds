#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*start=NULL,*q,*t;

int main()
{
    int ch;
    void insert_atbegin();
    void insert_atend();
    int insert_atpos();
    void delete_atbeg();
    void delete_atend();
    int delete_atpos();
    void display();
    while(1)
    {
        printf("\n\nMENU");
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\n\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("\nINSERT OPTIONS");
                    printf("\n1.Insert at the beginning\n2.Insert at the end\n3.Insert at a specified position\n4.Exit");
                    printf("\n\nEnter your choice:");
                    scanf("%d",&ch);

                    switch(ch)
                    {
                        case 1: insert_atbegin();
                                break;
                        case 2: insert_atend();
                                break;
                        case 3: insert_atpos();
                                break;
                        case 4: exit(0);
                        default: printf("Invalid Choice!!!");
                    }
                    break;
            case 2: display();
                    break;
            case 3:
                printf("\nDELETE OPTIONS");
                printf("\n1.Delete from the beginning\n2.Delete from the end\n3.Delete from a specified position\n4.Exit");
                printf("\n\nEnter your choice:");
                scanf("%d", &ch);

                switch (ch)
                {
                case 1:
                    delete_atbeg();
                    break;
                case 2:
                    delete_atend();
                    break;
                case 3:
                    delete_atpos();
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Invalid Choice!!!");
                    }
                    break;
            case 4: exit(0);
                    default:
                        printf("Invalid Choice!!!");
        }
    }
    return 0;
}

void insert_atbegin()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element:");
    scanf("%d",&num);
    t->data=num;

    if(start==NULL)        
    {
        t->next=NULL;
        start=t;
    }
    else
    {
        t->next=start;
        start=t;
    }
}

void insert_atend()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element:");
    scanf("%d",&num);
    t->data=num;
    t->next=NULL;

    if(start==NULL)        
    {
        start=t;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
        q=q->next;
        q->next=t;
    }
}

int insert_atpos()
{
    int pos,i,num;
    if(start==NULL)
    {
        printf("Empty List!!!");
        return 0;
    }

    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element:");
    scanf("%d",&num);
    printf("Enter the position for insertion:");
    scanf("%d",&pos);
    t->data=num;

    q=start;
    for(i=1;i<pos-1;i++)
    {
        if(q->next==NULL)
        {
            printf("Insertion not possible!!!");
            return 0;
        }

        q=q->next;
    }

    t->next=q->next;
    q->next=t;
    return 0;
}

void display()
{
    if(start==NULL)
    {
        printf("Empty List!!!");
    }
    else
    {
        q=start;
        printf("Elements in list:\n");
        while(q!=NULL)
        {
            printf("%d->",q->data);
            q=q->next;
        }
    }
}

void delete_atbeg()
{
    if(start==NULL)
    {
        printf("Empty List!!!");
    }
    else
    {
        q=start;
        start=start->next;
        printf("Deleted element is %d",q->data);
        free(q);
    }
}

void delete_atend()
{
    if(start==NULL)
    {
        printf("Empty List!!!");
    }
    else
    {
        q=start;
        while(q->next->next!=NULL)
        q=q->next;

        t=q->next;
        q->next=NULL;
        printf("Deleted element is %d",t->data);
        free(t);
    }
}

int delete_atpos()
{
    int pos,i;

    if(start==NULL)
    {
        printf("Empty List!!!");
        return 0;
    }

    printf("Enter the position for deletion:");
    scanf("%d",&pos);

    q=start;
    for(i=1;i<pos-1;i++)
    {
        if(q->next==NULL)
        {
            printf("Deletion not possible!!!");
            return 0;
        }
        q=q->next;
    }

    t=q->next;
    q->next=t->next;
    printf("Deleted element is %d",t->data);
    free(t);

    return 0;
}
