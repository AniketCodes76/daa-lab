#include <stdio.h>
#include<stdlib.h>
struct ITEM
{
    int item_id;
    float profit;
    float weight;
    float ratio;
};
void swap(struct ITEM *a, struct ITEM *b)
{
    struct ITEM temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(struct ITEM a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left].ratio > a[largest].ratio)
        largest = left;

    if (right < n && a[right].ratio > a[largest].ratio)
        largest = right;

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(struct ITEM a[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
    for (i = 0; i < n / 2; i++)
        swap(&a[i], &a[n - i - 1]);
}

int main()
{
    struct ITEM item[100];
    int n, i;
    float capacity;
    float profit = 0;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        item[i].item_id = i + 1;
        printf("Enter the profit and weight of item no %d: ",
               i + 1);
        scanf("%f %f", &item[i].profit, &item[i].weight);
        item[i].ratio = item[i].profit / item[i].weight;
    }
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);
    heapSort(item, n);
    printf("\nItem No profit Weight Amount to be taken\n");
    for (i = 0; i < n; i++)
    {
        float amount;
        if (capacity >= item[i].weight)
        {
            amount = 1.0;
            capacity = capacity - item[i].weight;
            profit = profit + item[i].profit;
        }
        else if (capacity > 0)
        {
            amount = capacity / item[i].weight;
            profit = profit + item[i].profit * amount;
            capacity = 0;
        }
        else
        {
            amount = 0.0;
        }
        printf("%d %.6f %.6f %.6f\n",
               item[i].item_id,
               item[i].profit,
               item[i].weight,
               amount);
    }
    printf("Maximum profit: %.6f\n", profit);
    return 0;
    
}