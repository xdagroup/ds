#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *head =NULL;

void check(int loc)
{
        int i = 0;
        struct node *ptr = head;
        while(ptr !=NULL && ptr->data != -1)
        {
            ptr=ptr->rlink;
            i++;
        }
        printf("%d allocations Done, %d allocations Available\n",i,loc-i);
}

void insert(int value)
{
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("\nOverflow!!!");
    else
    {
        ptr->data = value;
        if (head == NULL)
        {
            ptr->rlink = NULL;
            ptr->llink = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->rlink != NULL)
                temp = temp->rlink;

            temp->rlink = ptr;
            ptr->llink = temp;
            ptr->rlink = NULL;
        }
    }
}

void deallocate()
{
    head->rlink->llink = NULL;
    head = head->rlink;
    insert(-1);
}

void allocate()
{
    struct node *ptr = head;
    while(ptr !=NULL && ptr->data != -1)
        ptr=ptr->rlink;
    if(ptr !=NULL && ptr->data == -1)
        ptr->data = 1;
    if(ptr == NULL)
        printf("\nEmpty!!!\n");
}


void main()
{
    int count,x,choice;
    char ch;
    count = 0;
    while(1)
    {
        insert(-1);
        printf("Allocated Space :%d , Do you want to continue?(Y/N):",count+1);
        scanf(" %c",&ch);
        if(ch == 'Y' || ch == 'y')
            count++;
        else
            break;              
    }
    printf("\nMaximum allocation Space : %d\n",count);
    while(1)
    {
        printf("\n--------Menu---------\n");
        printf("\n1.Allocation\n2.Deallocation\n3.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nNumber of allocations : ");
                scanf("%d",&x);
                while(x!=0)
                {
                    allocate();
                    x--;
                }
                check(count);
                break;
            case 2:
                printf("\nNumber of Deallocations :");
                scanf("%d",&x);
                while(x!=0)
                {
                    deallocate();
                    x--;
                }
                check(count);
                break;
            case 3:
                printf("\nExiting!!!!\n");
                exit(0);
            default:
                printf("\nInvalid!!!!\n");
        }
    }
}
