#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
int randomizedPartition(int arr[], int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]);
    return partition(arr, low, high);
}
void randomizedQuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pivot - 1);
        randomizedQuickSort(arr, pivot + 1, high);
    }
}
int main()
{
    int n;
    srand(time(NULL));
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    randomizedQuickSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}