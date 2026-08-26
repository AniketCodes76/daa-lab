#include <stdio.h>
#include <stdlib.h>

int RecursivebinarySearch(int arr[], int low, int high, int key1)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key1)
    {
        return mid;
    }

    if (key1 < arr[mid])
    {
        return RecursivebinarySearch(arr, low, mid - 1, key1);
    }

    else
    {
        return RecursivebinarySearch(arr, mid + 1, high, key1);
    }
}

int IterativebinarySearch(int arr[], int n, int key2)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == key2)
        {
            return mid;
        }

        if (key2 < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int i, n;

    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements in sorted order:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int key;

    printf("\nEnter the element to search for using recursive binary search: ");
    scanf("%d", &key);

    int res = RecursivebinarySearch(arr, 0, n - 1, key);

    if (res != -1)
    {
        printf("\nThe key was found at index %d using recursive binary search.\n", res);
    }
    else
    {
        printf("\nThe key wasn't found using recursive binary search.\n");
    }

    int key2;

    printf("\nEnter the element to search for using iterative binary search: ");
    scanf("%d", &key2);

    int res2 = IterativebinarySearch(arr, n, key2);

    if (res2 != -1)
    {
        printf("\nThe key was found at index %d using iterative binary search.\n", res2);
    }
    else
    {
        printf("\nThe key wasn't found using iterative binary search.\n");
    }

    return 0;
}