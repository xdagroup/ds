#include <stdio.h>
int stack[100],i,j,choice=0,n,top=-1;

void push()
{
 int val;
 if (top == n-1 )
 printf("\nOverflow \n"); 
 else
 {
 printf("Enter the value:");
 scanf("%d",&val);
 top = top +1;
 stack[top] = val;
 }
}

void pop()
{
 if(top == -1)
 printf("\nUnderflow\n");
 else
 top = top -1;
}

void show()
{ 
 printf("\nStack is\n");
 for (i=top;i>=0;i--)
 {
 printf("%d\n",stack[i]);
 }
 if(top == -1)
 {
 printf("Stack is empty");
 } 
} 

void main ()
{

 printf("Enter the number of elements in the stack:");
 scanf("%d",&n);
 while(choice != 4)
 {
 printf("\n\n1.Push\n2.Pop\n3.Show\n4.Exit\nEnter your choice:");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 {
 push();
 break;
 }
 case 2:
 { 
 pop();
 break;
 }
 case 3:
 {
 show();
 break;
 }
 case 4:
 {
 break;
 }
 default:
 {
 printf("\nInvalid!!!\n");
 }
 };
 }
}




