#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m, cnt;
int g[N][N];
int dist[N];
bool st[N];
string sites[N];

int getId(string nowS)
{
    for (int i = 1; i <= cnt; i++)
        if (sites[i] == nowS)
            return i;
    sites[++cnt] = nowS;
    return cnt;
}

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
            printf("%s-%s ", sites[i].c_str(), sites[t].c_str());

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main()
{
    printf("请输入场地数和道路数:\n");
    scanf("%d %d", &n, &m);

    memset(g, 0x3f, sizeof g);
    printf("请输入道路连接的两个地点及其花费代价:\n");
    while (m--)
    {
        char s1[N];
        char s2[N];
        int t3;
        scanf("%s %s %d", s1, s2, &t3);
        getId(s1);
        getId(s2);
        g[getId(s1)][getId(s2)] = g[getId(s2)][getId(s1)] = min(g[getId(s1)][getId(s2)], t3);
    }
    printf("邻接矩阵:\n");
    printf("    ");
    for (int i = 1; i <= n; i++)
        printf("%4s", sites[i].c_str());
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%4s", sites[i].c_str());
        for (int j = 1; j <= n; j++)
            printf("%4d", g[i][j] > 0x3f ? 0 : g[i][j]);
        printf("\n");
    }
    printf("拟修建道路:");
    int t = prim();
    printf("\n最小花费:%d\n", t);

    return 0;
}