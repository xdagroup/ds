#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, arr[100], num, search, l = 0, middle;
    printf("\nEnter the number of elements:");
    scanf("%d", &num);
    int h = num - 1;
    for (i = 0; i < num; i++)
    {
        printf("\nEnter value %d:", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter search value:");
    scanf("%d", &search);
    while (l <= h)
    {
        middle = (l + h) / 2;
        if (search == arr[middle])
        {
            printf("Position of %d = %d", search, middle+1);
            exit(1);
        }
        else if (search < arr[middle])
        {
            h = middle - 1;
        }
        else
        {
            l = middle + 1;
        }
    }
    return 0;
}
