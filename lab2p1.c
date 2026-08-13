#include <stdio.h>
#include <stdlib.h>

void toBinary(int n)
{
    if (n == 0)
        return;

    toBinary(n / 2);
    printf("%d", n % 2);
}

int main()
{
    FILE *fp;
    int ar[10000], n = 0, i;

    fp = fopen("lab2p1.dat", "r");

    if (fp == NULL)
    {
        printf("Error in file opening\n");
        return 1;
    }

    while(fscanf(fp, "%d", &ar[n])==1)
    {
        n++;
    }

    fclose(fp);

    for (i = 0; i < n; i++)
    {
        printf("Binary equivalent of %d is: ", ar[i]);

        if (ar[i] == 0)
            printf("0");
        else
            toBinary(ar[i]);

        printf("\n");
    }

    return 0;
}