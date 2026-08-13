#include <stdio.h>

int main()
{
    FILE *fp;
    int arr[100];
    int n, i, j;
    int duplicateCount = 0;

    fp = fopen("daaprog.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fscanf(fp, "%d", &n);

    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &arr[i]);

    fclose(fp);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicateCount++;
                break;
            }
        }
    }

    printf("Total duplicate elements = %d\n", duplicateCount);

    int maxCount = 0, mostRepeated;

    for (i = 0; i < n; i++)
    {
        int count = 1;

        int alreadyCounted = 0;
        for (j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                alreadyCounted = 1;
                break;
            }
        }

        if (alreadyCounted)
            continue;

        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            mostRepeated = arr[i];
        }
    }

    printf("Most repeating element = %d\n", mostRepeated);
    printf("Number of occurrences = %d\n", maxCount);

    return 0;
}