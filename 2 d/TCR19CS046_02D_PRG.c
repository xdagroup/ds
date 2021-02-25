#include<stdio.h>
#include<conio.h>
#define MAX 10

int deque[LIM];
int left=-1, right=-1;

void insert_right(void);
void insert_left(void);
void delete_right(void);
void delete_left(void);
void show(void);

int main()
{
 int choice;
 do
 {
  printf("\n1.Insert at right ");
  printf("\n2.Insert at left ");
  printf("\n3.Delete from right ");
  printf("\n4.Delete from left ");
  printf("\n5.Display ");
  printf("\n6.Exit");
  printf("\n\nEnter your choice:");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
    insert_right();
    break;
   case 2:
    insert_left();
    break;
   case 3:
    delete_right();
    break;
   case 4:
    delete_left();
    break;
   case 5:
    show();
    break;
  }
 }while(choice!=6);
 getch();
 return 0;
}
void insert_right()
{
 int val;
 printf("\nEnter the value:");
 scanf("%d",&val);
 if( (left==0 && right==LIM-1) || (left==right+1) )
 {
  printf("\nOVERFLOW");
 }
 if(left==-1)        
 {
  left=0;
  right=0;
 }
 else
 {
  if(right==LIM-1)
   right=0;
  else
   right=right+1;
 }
 deque[right]=val;
}
void insert_left()
{
 int val;
 printf("\nEnter the value:");
 scanf("%d",&val);
 if( (left==0 && right==LIM-1) || (left==right+1) )
 {
  printf("\nOVERFLOW");
 }
 if(left==-1)       
 {
  left=0;
  right=0;
 }
 else
 {
  if(left==0)
   left=LIM-1;
  else
   left=left-1;
 }
 deque[left]=val;
}
void delete_right()
{
 if(left==-1)
 {
  printf("\nUNDERFLOW");
  return;
 }
 printf("\nThe deleted element is %d\n", deque[right]);
 if(left==right)         
 {
  left=-1;
  right=-1;
 }
 else
 {
  if(right==0)
   right=LIM-1;
  else
   right=right-1;
 }
}
void delete_left()
{
 if(left==-1)
 {
  printf("\nUNDERFLOW");
  return;
 }
 printf("\nThe deleted element is %d\n", deque[left]);
 if(left==right)         
 {
  left=-1;
  right=-1;
 }
 else
 {
  if(left==LIM-1)
   left=0;
  else
   left=left+1;
 }
}
void show()
{
 int front=left, rear=right;
 if(front==-1)
 {
  printf("\nQueue is Empty\n");
  return;
 }
 printf("\nThe elements in the queue are: ");
 if(front<=rear)
 {
  while(front<=rear)
  {
   printf("%d\t",deque[front]);
   front++;
  }
 }
 else
 {
  while(front<=LIM-1)
  {
   printf("%d\t",deque[front]);
   front++;
  }
  front=0;
  while(front<=rear)
  {
   printf("%d\t",deque[front]);
   front++;
  }
 }
 printf("\n");
}
