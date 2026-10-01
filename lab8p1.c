#include <stdio.h>
#include <limits.h>
int main() {
    int n, i, j, k, l;
    int rows[20], cols[20];
    int m[20][20], s[20][20];
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter row and col size of A%d: ", i);
        scanf("%d %d", &rows[i], &cols[i]);
        if (i > 1 && rows[i] != cols[i - 1]) {
            printf("Error: Matrix dimensions are not compatible.\n");
            return 0;
        }
    }
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
        s[i][i] = 0;
    }
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j]
                         + rows[i] * cols[k] * cols[j];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\nM Table:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j < i)
                printf("0 ");
            else
                printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\nS Table:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j <= i)
                printf("0 ");
            else
                printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    printf("\nOptimal parenthesization: ");
    return 0;
}