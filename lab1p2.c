#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[100], arr2[100];
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter the %dth element in the array: ", i);
        scanf("%d", &arr[i]);
    }

    arr2[0]= arr[0];

    for(i=0; i<n ; i++)
    {
        arr2[i]= arr2[i-1] + arr[i];
    }

    for(i=0; i<n; i++)
    {
        printf("\n%dth element in the first array is %d", i, arr[i]);
    }

    for(i=0; i<n; i++)
    {
        printf("\n%dth element in the second array is %d", i, arr2[i]);
    }
    return 0;
}