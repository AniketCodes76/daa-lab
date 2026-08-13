#include<stdio.h>
#include<stdlib.h>

int maxmin(int arr[], int low, int high, int *min, int *max)
{
    int mid;
    int max1, max2, min1, min2;
    if(low == high)
    {
        *min = *max = arr[low];
        return 0;
    }
    if(high == low + 1)
    {
        if(arr[low] > arr[high])
        {
            *max = arr[low];
            *min = arr[high];
        }
        else
        {
            *max = arr[high];
            *min = arr[low];
        }
        return 0;
    }
    mid = (low + high) / 2;
    maxmin(arr,low, mid, &min1, &max1);
    maxmin(arr, mid+1, high, &min2, &max2);
    *max = (max1 > max2) ? max1 : max2;
    *min = (min1 < min2) ? min1 : min2;
}
int main()
{
    int n, i;
    int min, max;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    maxmin(arr, 0, n - 1, &min, &max);
    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);
    return 0;
}