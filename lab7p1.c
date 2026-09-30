#include <stdio.h>
#include <limits.h>

#define MAX 100

int main()
{
    int n, source;
    int graph[MAX][MAX];
    int dist[MAX], visited[MAX], parent[MAX];
    FILE *fp;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter the Source Vertex: ");
    scanf("%d", &source);

    fp = fopen("inDiAdjMat1.dat", "r");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &graph[i][j]);

    fclose(fp);

    source--;

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < n; count++)
    {
        int min = INT_MAX, u = -1;

        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nSource Destination Cost Path\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d ", source + 1, i + 1, dist[i]);

        if (i == source)
        {
            printf("-\n");
            continue;
        }

        int path[MAX], k = 0;
        int v = i;

        while (v != -1)
        {
            path[k++] = v;
            v = parent[v];
        }

        for (int j = k - 1; j >= 0; j--)
        {
            printf("%d", path[j] + 1);

            if (j != 0)
                printf("->");
        }

        printf("\n");
    }

    return 0;
}