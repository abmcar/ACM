#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, m;
int dis[5050][5050];
int nowDis[5050];
bool ok[5050];
bool isFind = true;

void addEdge(int t1, int t2, int t3)
{
    dis[t1][t2] = t3;
    dis[t2][t1] = t3;
}

signed main()
{
    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset(ok, 0, sizeof ok);
        for (int i = 0; i <= n; i++)
            nowDis[i] = 1e9;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dis[i][j] = 1e9;
        for (int i = 1; i <= m; i++)
        {
            int from, to, val;
            scanf("%d %d %d", &from, &to, &val);
            addEdge(from, to, val);
        }
        int nowCost = 0;
        for (int i = 0; i < n; i++)
        {
            int t = -1;
            for (int j = 1; j <= n; j++)
            {
                if (ok[j])
                    continue;
                if (t == -1 || nowDis[t] > nowDis[j])
                    t = j;
            }
            if (i != 0)
            {
                if (nowDis[t] == 1e9)
                {
                    nowCost = 1e9;
                    break;
                }
                nowCost += nowDis[t];
            }
            ok[t] = true;
            for (int j = 1; j <= n; j++)
                if (nowDis[j] > dis[t][j])
                    nowDis[j] = dis[t][j];
        }
        if (nowCost == 1e9)
            cout << "There is no minimum spanning tree." << endl;
        else
            cout << nowCost << endl;
    }
    return 0;
}