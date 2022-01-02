#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF)
            return INF;

        if (i)
            res += dist[t];
        st[t] = true;
        if (i)
            printf("%d-%d ", i, t);

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main()
{
    scanf("%d %d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while (m--)
    {
        int t1, t2, t3;
        scanf("%d %d %d", &t1, &t2, &t3);
        g[t1][t2] = g[t2][t1] = min(g[t1][t2], t3);
    }

    int t = prim();
    printf("%d\n", t);

    return 0;
}