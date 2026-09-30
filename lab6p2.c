#include <stdio.h>

#define MAX 100

struct Edge
{
    int u, v, w;
};

/* Find the parent of a vertex */
int find(int parent[], int i)
{
    while (parent[i] != i)
        i = parent[i];

    return i;
}

/* Join two sets */
void unionSet(int parent[], int u, int v)
{
    int a = find(parent, u);
    int b = find(parent, v);

    parent[a] = b;
}

/* Sort edges according to weight */
void sortEdges(struct Edge edges[], int m)
{
    int i, j;
    struct Edge temp;

    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, m;
    struct Edge edges[MAX];

    int parent[MAX];
    int i;
    int count = 0;
    int totalCost = 0;

    /* Input number of vertices and edges */
    scanf("%d %d", &n, &m);

    /* Input edges */
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    /* Sort edges by weight */
    sortEdges(edges, m);

    /* Initially every vertex is its own parent */
    for (i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    printf("Edge Cost\n");

    /* Kruskal's Algorithm */
    for (i = 0; i < m && count < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        /* Check if adding edge creates a cycle */
        if (find(parent, u) != find(parent, v))
        {
            printf("%d--%d %d\n",
                   u, v, edges[i].w);

            totalCost += edges[i].w;
            count++;

            unionSet(parent, u, v);
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n",
           totalCost);

    return 0;
}