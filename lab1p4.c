#include <stdio.h>

void EXCHANGE(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2)
{
    int i;

    for (i = p2 - 1; i > 0; i--)
    {
        EXCHANGE(&p1[i], &p1[i - 1]);
    }
}

int main()
{
    int A[100];
    int N, i, p2;

    printf("Enter size of array: ");
    scanf("%d", &N);

    printf("Enter array elements:\n");
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);

    printf("Enter number of elements to rotate: ");
    scanf("%d", &p2);

    printf("Before ROTATE: ");
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);

    ROTATE_RIGHT(A, p2);

    printf("\nAfter ROTATE: ");
    for (i = 0; i < N; i++)
        printf("%d ", A[i]);

    return 0;
}