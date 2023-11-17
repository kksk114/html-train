#include <stdio.h>
#include <stdlib.h>

void init(int parents[], int m)
{
    int k;
    for (k = 0; k < m; k++)
    {
        parents[k] = -1;
    }
}

int find_root(int x, int parents[])
{
    int x_root = x;
    while (parents[x_root] != -1)
    {
        x_root = parents[x_root];
    }
    return x_root;
}

int union_parents(int x, int y, int parents[])
{
    int x_root = find_root(x, parents);
    int y_root = find_root(y, parents);

    if (x_root == y_root)
    {
        return 0;
    }
    else
    {
        parents[x_root] = y_root;
        return 1;
    }
}

int main()
{
    int i, n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int parents[n];
    int members[m][2];

    for (i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &members[i][j]);
        }
    }

    init(parents, n);

    for (i = 0; i < m; i++)
    {
        int x = members[i][0];
        int y = members[i][1];

        if (union_parents(x, y, parents) == 0)
        {
            printf("%d\n", i + 1);
            exit(0);
        }
    }

    printf("-1\n");

    return 0;
}