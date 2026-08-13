#include<stdio.h>
#include<stdlib.h>
int toGCD(int a, int b)
{
    if(b == 0)
        return a;
    return toGCD(b, a%b);

}

int main()
{
    FILE *fp;
    int ar[10000], n = 0, i;

    fp = fopen("daaprog.txt", "r");

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

    for (i = 0; i < n-1; i+=2)
    {   
        printf("\nThe gcd of %d and %d is %d", ar[i], ar[i+1], toGCD(ar[i], ar[i+1]));
    }
}