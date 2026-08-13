#include <stdio.h>
#include <stdlib.h>

#define MAX 500

int c = 0;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        c++;

        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. Error (Exit)\n");

    printf("\nEnter the choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            n = readFile("inAsc.dat", arr);
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
            printf("Enter the correct value :)\n");
            return 0;
    }

    if (n == -1)
    {
        return 1;
    }

    printf("\nBefore Sorting:\n");
    printArray(arr, n);

    c = 0;

    mergeSort(arr, 0, n - 1);

    switch (choice)
    {
        case 1:
            writeFile("outMergeAsc.dat", arr, n);
            break;

        case 2:
            writeFile("outMergeDesc.dat", arr, n);
            break;

        case 3:
            writeFile("outMergeRand.dat", arr, n);
            break;
    }

    printf("\nAfter Sorting:\n");
    printArray(arr, n);

    printf("\nNumber of comparisons: %d\n", c);

    return 0;
}