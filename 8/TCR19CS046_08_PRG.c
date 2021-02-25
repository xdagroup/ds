#include <stdio.h>
#include <stdlib.h>

void first_fit(int B[],int b,int P[],int p){
  int a[p],f,i,j;
  for(i=0;i<p;i++){
    f=-1;
    for(j=0;j<b;j++){
      if(B[j]>=P[i]){
        f=j; 
        break;
      }
    }
      if(f==-1){
        a[i]=-2;
      }
      else{
        B[f]=B[f]-P[i];
        a[i]=f;
      }
    }
    printf("------------Memory Allocation Details------------\n");
    for(i=0;i<p;i++){
      printf("%d allocated at %d\n",P[i],a[i]+1);
    }
}

void best_fit(int B[],int b,int P[],int p){
   int a[p],i,j,best;
   for(i=0;i<p;i++){
     best=-1;
     for(j=0;j<b;j++){
       if(B[j]>P[i]){
         best=j;
         break;         
       }
     }
     for(j=0;j<b;j++){
       if( B[j]>P[i]&&B[j]<B[best])
         best=j;     
     }

   if(best==-1){
     a[i]=-2;
   }
   else{
     B[best]=B[best]-P[i];  
     a[i]=best;
   }
 }
   printf("------------Memory Allocation Details------------\n");
   for(i=0;i<p;i++){
     printf("%d allocated at %d\n",P[i],a[i]+1);
   }
}

void worst_fit(int B[],int b,int P[],int p){
  int a[p],i,j,max,f;
  for(i=0;i<p;i++){
    f=0;
    max=0;
    for(j=0;j<b;j++){
      if(B[j]>P[i]&&B[j]>B[max]){
        max=j;
        f++;
      }     
    }
    if(f==0){
    a[i]=-2;
  }
  else{
    B[max]=B[max]-P[i];   
    a[i]=max;
  }
}
  printf("------------Memory Allocation Details------------\n");
  for(i=0;i<p;i++){
    printf("%d allocated at %d \n",P[i],a[i]+1);
  }
}


int main()
{
  int block_size[20];
  int process_size[10];
  int b,p,c=0,i;
  printf("Enter the number of blocks:\n");
  scanf("%d",&b);
  printf("Enter the block sizes :\n");
  for(i=0;i<b;i++)
    scanf("%d",&block_size[i]);
  printf("Enter the number of processes:\n");
  scanf("%d",&p);
  printf("Enter the process sizes :\n");
  for(i=0;i<p;i++)
    scanf("%d",&process_size[i]);
  printf("1.First fit\n2.Best fit\n3.Worst fit\n4.Exit\nEnter your choice:");
  scanf("%d",&c);
  switch(c)
  {
      case 1:first_fit(block_size,b,process_size,p);
            break;
      case 2:best_fit(block_size,b,process_size,p);
            break;
      case 3:worst_fit(block_size,b,process_size,p);
             break;
      case 4: printf("Exiting...");
              exit(0);
  }
}
