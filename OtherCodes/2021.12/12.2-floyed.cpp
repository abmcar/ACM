#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3 + 10;

int main()
{
    int t, n, cnt;
    bool dis[Maxn][Maxn];
    bool ok[Maxn];
    scanf("%d", &t);
    while (t--)
    {
        memset(ok, false, sizeof ok);
        memset(dis, false, sizeof dis);
        cnt = 0;
        scanf("%d", &n);
        int temp;
        for (int i = 1; i <= n; i++)
        {
            while (1)
            {
                scanf("%d", &temp);
                if (temp == 0)
                    break;
                dis[i][temp] = 1;
            }
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (dis[i][k] && dis[k][j])
                        dis[i][j] = true;
        for (int i = 1; i <= n; i++)
        {
            if (!ok[i])
            {
                ok[i] = true;
                cnt++;
                for (int j = 1; j <= n; j++)
                {
                    if (dis[i][j] && dis[j][i])
                        ok[j] = true;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}