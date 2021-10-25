#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int n, m, ans, strPos;
bool inQ[Maxn];
int dis[Maxn][Maxn];
vector<int> g[Maxn], gg[Maxn];

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        dis[t1][t2] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i][k] && dis[k][j])
                    dis[i][j] = 1;
}

void work()
{
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (dis[i][j] || dis[j][i])
                cnt++;
        if (cnt == n - 1)
            ans++;
    }
    cout << ans;
}

int main()
{
    Buff;
    init();
    work();
    return 0;
}