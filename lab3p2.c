#include <stdio.h>
#include <stdlib.h>

#define MAX 500

int c = 0;
int bestCase = 1;
int worstCase = 1;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        c++;

        if (arr[j] <= pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    int pos = i + 1;
    int leftSize = pos - low;
    int rightSize = high - pos;

    if (leftSize == 0 || rightSize == 0)
        bestCase = 0;

    if (leftSize > (high - low + 1) / 2 ||
        rightSize > (high - low + 1) / 2)
        bestCase = 0;

    if (leftSize != 0 && rightSize != 0)
        worstCase = 0;

    return pos;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int readFile(char filename[], int arr[])
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error in opening the file\n");
        return -1;
    }

    int n = 0;

    while (n < MAX && fscanf(fp, "%d", &arr[n]) == 1)
    {
        n++;
    }

    fclose(fp);

    return n;
}

int writeFile(char filename[], int arr[], int n)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("Error in opening the output file\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", arr[i]);
    }

    fclose(fp);

    return 0;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[MAX];
    int n, choice;

    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. Error (Exit)\n");

    printf("\nEnter option: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            n = readFile("inAsce.dat", arr);
            break;

        case 2:
            n = readFile("inDesc.dat", arr);
            break;

        case 3:
            n = readFile("inRand.dat", arr);
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Enter the correct value\n");
            return 0;
    }

    if (n == -1)
    {
        return 1;
    }

    printf("\nBefore Sorting:\n");
    printArray(arr, n);

    c = 0;
    bestCase = 1;
    worstCase = 1;

    quickSort(arr, 0, n - 1);

    switch (choice)
    {
        case 1:
            writeFile("outQuickAsce.dat", arr, n);
            break;

        case 2:
            writeFile("outQuickDesc.dat", arr, n);
            break;

        case 3:
            writeFile("outQuickRand.dat", arr, n);
            break;
    }

    printf("\nAfter Sorting:\n");
    printArray(arr, n);

    printf("\nNumber of Comparisons: %d\n", c);

    if (bestCase)
    {
        printf("Scenario: Best-case partitioning\n");
    }
    else if (worstCase)
    {
        printf("Scenario: Worst-case partitioning\n");
    }
    else
    {
        printf("Scenario: Average-case partitioning\n");
    }

    return 0;
}