#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, arr[100], num, search;
    printf("Enter the number of elements:");
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        printf("\nEnter value %d:", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the search value:");
    scanf("%d", &search);
    for (i = 0; i < num; i++)
    {
        if (arr[i] == search)
        {
            printf("Position of search value = %d", i+1);
            break;
        }
    }
    if (i == num)
    {
        printf("%d Not Found!!!", search);
    }
}