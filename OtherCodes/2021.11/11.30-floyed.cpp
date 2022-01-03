#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, cnt;
int bd[123][123];
int dis[123][123];
int used[123];

void work()
{
    cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            bd[i][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        used[i] = 0;
        while (1)
        {
            int temp;
            cin >> temp;
            if (temp == 0)
                break;
            bd[i][temp] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (bd[i][j])
                dis[i][j] = 1;
            else
                dis[i][j] = 1e9;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
    for (int i = 1; i <= n; i++)
    {
        if (used[i])
            continue;
        used[i] = 1;
        cnt++;
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] < 1e9 && dis[j][i] < 1e9)
                used[j] = 1;
        }
    }
    cout << cnt << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}
/* 
3
5
2 4 3 0
4 5 0
0
0
1 0
3
2 0
0
2 1 0
3
2 0
3 0
0

 */