#include <stdio.h>
#include <limits.h>

#define MAX 100

int main()
{
    int n, start;
    int cost[MAX][MAX];
    int mst[MAX][MAX] = {0};

    int key[MAX];
    int parent[MAX];
    int visited[MAX] = {0};

    FILE *fp;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);

    start--;   // convert to 0-based indexing

    /* Open input file */
    fp = fopen("inUnAdjMat.dat", "r");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    /* Read cost adjacency matrix */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &cost[i][j]);
        }
    }

    fclose(fp);

    /* Initialize */
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[start] = 0;

    /* Prim's Algorithm */
    for (int count = 0; count < n; count++)
    {
        int min = INT_MAX;
        int u = -1;

        /* Find vertex with minimum key */
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        /* Add vertex to MST */
        visited[u] = 1;

        /* Update adjacent vertices */
        for (int v = 0; v < n; v++)
        {
            if (cost[u][v] != 0 &&
                !visited[v] &&
                cost[u][v] < key[v])
            {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    /* Construct MST adjacency matrix */
    int totalCost = 0;

    for (int i = 0; i < n; i++)
    {
        if (parent[i] != -1)
        {
            mst[i][parent[i]] = cost[i][parent[i]];
            mst[parent[i]][i] = cost[i][parent[i]];

            totalCost += cost[i][parent[i]];
        }
    }

    /* Display MST */
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mst[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Weight of the Spanning Tree: %d\n", totalCost);

    return 0;
}