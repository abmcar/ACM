#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug
#define int long long

using namespace std;

const int Maxn = 1e7 + 10;
const int N = 2333;
const ll Mod = 1e9 + 7;

int n, m;
int dis[N][N];
int nowDis[N];
bool ok[N];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    while (cin >> n >> m)
    {
        for (int i = 0; i <= n; i++)
            nowDis[i] = Maxn, ok[i] = false;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dis[i][j] = Maxn;
        int arg1, arg2, arg3;
        while (m--)
        {
            cin >> arg1 >> arg2 >> arg3;
            dis[arg1][arg2] = min (dis[arg1][arg2], arg3);
            dis[arg2][arg1] = min (dis[arg2][arg1], arg3);
        }
        int nowCost = 0;
        for (int i = 0; i < n; i++)
        {
            int t = -1;
            for (int j = 1; j <= n; j++)
                if (!ok[j] && (t == -1 || nowDis[t] > nowDis[j]))
                    t = j;
            if (i && nowDis[t] == Maxn)
            {
                nowCost = Maxn;
                break;
            }
            if (i != 0)
                nowCost += nowDis[t];
            ok[t] = true;
            for (int j = 1; j <= n; j++)
                nowDis[j] = min(nowDis[j], dis[t][j]);
        }
        if (nowCost == Maxn)
            cout << "There is no minimum spanning tree." << endl;
        else
            cout << nowCost << endl;
    }
    return 0;
}