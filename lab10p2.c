#include <stdio.h>

int main()
{
    int n, f[100], fit[100] = {0}, count = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);

    f[0] = 1;
    f[1] = 2;
    count = 2;

    while (f[count - 1] + f[count - 2] <= n)
    {
        f[count] = f[count - 1] + f[count - 2];
        count++;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        if (f[i] <= n)
        {
            fit[i] = 1;
            n -= f[i];
        }
    }

    printf("Fibonacci representation (least significant fit first):\n");
    for (int i = 0; i < count; i++)
        printf("%d ", fit[i]);

    printf("\n");
    return 0;
}