#include <stdio.h>
#include<stdlib.h>

struct term
{
    int coeff;
    int expo;
};

struct poly
{
    int n;
    struct term *t;
};

void display(struct poly *p)
{
    for(int i=0;i<p->n;i++)
    {
        printf("%dx%d ",p->t[i].coeff,p->t[i].expo);
    }
}
struct poly* add(struct poly *p1, struct poly *p2)
{
    struct poly *p3;
    p3=(struct poly*)malloc(sizeof(struct poly));
    p3->t=(struct term*)malloc((p2->n+p1->n)*sizeof(struct term));
    int i=0,j=0,k=0;
    while(i<p1->n && j<p2->n)
    {
        if(p1->t[i].expo>p2->t[j].expo)
            p3->t[k++]=p1->t[i++];
        else if(p1->t[i].expo<p2->t[j].expo)
                p3->t[k++]=p2->t[j++];
            else
            {
                p3->t[k].expo=p1->t[i].expo;
                p3->t[k++].coeff=p1->t[i++].coeff + p2->t[j++].coeff;
            }   
    }
   while(i<p1->n)
    {
        p3->t[k++]=p1->t[i++];
    }
   while(j<p2->n)
    {
        p3->t[k++]=p2->t[j++];
    }
    p3->n=k;;
    return p3;
    
}

void sub(struct poly *p1, struct poly *p2)
{
    struct poly *p3;
    p3=(struct poly*)malloc(sizeof(struct poly));
    p3->t=(struct term*)malloc((p2->n+p1->n)*sizeof(struct term));
    int i=0,j=0,k=0;
    while(i<p1->n && j<p2->n)
    {
        if(p1->t[i].expo<p2->t[j].expo)
            p3->t[k++]=p1->t[i++];
        else if(p1->t[i].expo>p2->t[j].expo)
                p3->t[k++]=p2->t[j++];
            else
            {
                p3->t[k].expo=p1->t[i].expo;
                p3->t[k++].coeff=p1->t[i++].coeff - p2->t[j++].coeff;
            }   
    }
   while(i<p1->n)
    {
        p3->t[k++]=p1->t[i++];
    }
   while(j<p2->n)
    {
        p3->t[k].expo=p2->t[j].expo;
        p3->t[k++].coeff=p2->t[j++].coeff *-1;
    }
    p3->n=k;;
    printf("\nSubtracted polynomial is : ");
    display(p3);
    
}

void multiply(struct poly *p1, struct poly *p2)
{
    struct poly *p3;int k=0;
    p3=(struct poly*)malloc(sizeof(struct poly));
    p3->t=(struct term*)malloc((p2->n+p1->n)*sizeof(struct term));
    struct poly *p4;
    p4=(struct poly*)malloc(sizeof(struct poly));
    p4->t=(struct term*)malloc((p2->n+p1->n)*sizeof(struct term));
    p4->n=0;
    for(int i=0;i<p1->n;i++)
    {
        k=0;
        for(int j=0;j<p2->n;j++)
        {
            p3->t[k].coeff=p2->t[j].coeff*p1->t[i].coeff;
            p3->t[k++].expo=p2->t[j].expo+p1->t[i].expo;
            
        }
        
        p3->n=k;
        
        p4=add(p3,p4);
        
    }
    printf("\nMultiplied polynomial is:");
    display(p4);
}


int main()
{
    struct poly p1,p2;
    printf("\nEnter the number of terms in P1:");
    scanf("%d",&p1.n);
    printf("\nEnter the number of terms in P2:");
    scanf("%d",&p2.n);
    struct poly *p3;
    p3=(struct poly*)malloc(sizeof(struct poly));
    p3->t=(struct term*)malloc((p2.n+p1.n)*sizeof(struct term));
    printf("Enter the terms of P1 \n");
    p1.t=(struct term*)malloc(p1.n*sizeof(struct term));
    p2.t=(struct term*)malloc(p2.n*sizeof(struct term));
    for(int i=0;i<p1.n;i++)
    {
        printf("Enter Term %d:",i+1);
        scanf("%d %d", &p1.t[i].coeff,&p1.t[i].expo);
    }
    printf("Enter the terms of P2 \n");
    for(int i=0;i<p2.n;i++)
    {
        printf("Enter Term %d:",i+1);
        scanf("%d %d", &p2.t[i].coeff,&p2.t[i].expo);
    }
    int ch;
    printf("\n 1. Add");
    printf("\n 2. Subtract");
    printf("\n 3. Multiply");
    printf("\n Enter your Choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: p3=add(&p1,&p2);
                printf("\nAdded polynomial is : ");
                display(p3);
                break;
        case 2: sub(&p1,&p2);
                break;
        case 3: multiply(&p1,&p2);
                break;
        default: printf("\nInvalid!!!");        
    }
    return 0;
}

