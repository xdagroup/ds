#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;
void ins_beg()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOverflow!!!");
    }
    else
    {
        printf("\nEnter the element:");
        scanf("%d", &item);

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = item;
            head = ptr;
        }
        else
        {
            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\nInserted Successfully!!!\n");
    }
}
void ins_end()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOverflow!!!");
    }
    else
    {
        printf("\nEnter the element:");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
    printf("\nInserted Successfully!!!\n");
}
void ins_spec()
{
    struct node *ptr, *temp;
    int item, loc, i;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOverflow!!!");
    }
    else
    {
        temp = head;
        printf("Enter the location:");
        scanf("%d", &loc);
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\n There are less than %d elements", loc);
                return;
            }
        }
        printf("Enter the element:");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
        printf("\nInserted Successfully!!!\n");
    }
}
void del_beg()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUnderflow!!!");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nDeleted Successfully!!!\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nDeleted Successfully!!!\n");
    }
}
void del_end()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUnderflow!!!");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nDeleted Successfully!!!n");
    }
    else
    {
        ptr = head;
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        printf("\nDeleted Successfully!!!\n");
    }
}
void del_spec()
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the data after which the node is to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    while (ptr->data != val)
        ptr = ptr->next;
    if (ptr->next == NULL)
    {
        printf("\nCannot delete\n");
    }
    else if (ptr->next->next == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        printf("\nDeleted Successfully!!!\n");
    }
}
void display()
{
    struct node *ptr;
    printf("\n ----VALUES----\n");
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter the search item:\n");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("\nitem found at location %d ", i + 1);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("\nItem not found!!!\n");
        }
    }
}
void main ()  
{  
int choice =0;  
    while(choice != 9)  
    {  
        printf("\n---------MENU----------\n");  
        printf("\n1.Insertion at begining\n2.Insertion at end\n3.Insertion at any location\n4.Deletion from beginning\n5.Deletion from end\n6.Deletion of the node after the given data\n7.Search\n8.Display\n9.Exit\n");
        printf("\nEnter your choice:\n");
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            ins_beg();  
            break;  
            case 2:  
                    ins_end();  
            break;  
            case 3:  
            ins_spec();  
            break;  
            case 4:  
            del_beg();  
            break;  
            case 5:  
            del_end();  
            break;  
            case 6:  
            del_spec();  
            break;  
            case 7:  
            search();  
            break;  
            case 8:  
            display();  
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("Invalid!!!");  
        }  
    }  
}  
