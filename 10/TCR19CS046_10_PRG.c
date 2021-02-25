#include <stdio.h>
#include <stdlib.h>

void selection(int a[],int n){
  int i,j,min,temp,pos;
  for(i=0;i<n-1;i++){
    min=a[i];
    pos=i;
    for(j=i+1;j<n;j++){
      if(min>a[j]){
        min=a[j];
        pos=j;
      }
    }
    temp=a[i];
    a[i]=a[pos];
    a[pos]=temp;
  }
  printf("The array sorted using selection sort is: \n");
  for(i=0;i<n;i++)
  printf(" %d ",a[i]);
}

void bubble(int a[],int n){
  int i,j,temp;
  for(i=0;i<n;i++){
    for(j=0;j<n-1;j++){
      if(a[j]>a[j+1]){
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
  printf("The array sorted using bubble sort is: \n");
  for(i=0;i<n;i++)
  printf(" %d ",a[i]);
}

void merge(int l[],int nl,int r[],int rl,int a[]){
  int i=0,j=0,k=0;
  while(i<nl&&j<rl){
    if(l[i]<r[i]){
      a[k++]=l[i++];
    }
    else{
      a[k++]=r[j++];
    }
  }
  while(i<nl)
  a[k++]=l[i++];
  while(j<rl)
  a[k++]=r[j++];
}

void merge_sort(int a[],int n){
  if(n<2){
    return;
  }
  int mid=n/2,i,j=0;
  int left[mid],right[n-mid];
  for(i=0;i<mid;i++)
  left[i]=a[i];
  for(j=0,i=mid;i<n;j++,i++)
  right[j]=a[i];
  merge_sort(left,sizeof(left)/sizeof(int));
  merge_sort(right,sizeof(right)/sizeof(int));
  merge(left,sizeof(left)/sizeof(int),right,sizeof(right)/sizeof(int),a);
  for(i=0;i<n;i++)
  printf(" %d ",a[i]);
  printf("\nThis is the array sorted using merge sort\n");
}

void insertion(int a[],int n){
  int i,val,hole,temp;
  for(i=0;i<n;i++){
    val=a[i];
    hole=i;
    while(hole>0&&a[hole-1]>val){
      temp=a[hole];
      a[hole]=a[hole-1];
      a[hole-1]=temp;
      hole--;
    }
    a[hole]=val;
  }
  printf("The array sorted using insertion sort is: \n");
  for(i=0;i<n;i++)
  printf(" %d ",a[i]);

}


int main(){
  int n,unsort[20],i,c;
  printf("Enter the number of elements:\n");
  scanf("%d",&n);
  printf("Enter the elements:\n");
  for(i=0;i<n;i++)
  scanf("%d",&unsort[i]);
  printf("\n1.Selection sort\n2.Bubble sort\n3.Merge sort\n4.Insertion sort\n5.Exit\nEnter your choice:");
  scanf("%d",&c);
  switch (c) {
      case 1:selection(unsort,n);
             break;
      case 2:bubble(unsort,n);break;
      case 3:merge_sort(unsort,n);break;
      case 4:insertion(unsort,n);break;
      case 5:printf("Exiting!!!!");
             exit(0);
    }
  }
