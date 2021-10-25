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
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const ll Maxn = 1e4 + 10;
const ll Mod = 1e9 + 7;

ll nx[] = {0, 1, 0, -1};
ll ny[] = {1, 0, -1, 0};
ll n, m, k, d, ans;
ll dis[Maxn][Maxn];
ll val[Maxn][Maxn];
queue<ll> qx, qy, qt;

void init()
{
    cin >> n >> m >> k >> d;
    for (ll i = 1; i <= m; i++)
    {
        ll t1, t2;
        cin >> t1 >> t2;
        qx.push(t1);
        qy.push(t2);
        qt.push(0);
    }
    for (ll i = 1; i <= k; i++)
    {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        val[t1][t2] += t3;
        // dis[t1][t2] = 0;
    }
    for (ll i = 1; i <= d; i++)
    {
        ll t1, t2;
        cin >> t1 >> t2;
        val[t1][t2] = -1;
    }
    for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= n; j++)
        dis[i][j] = 1e12;
}

void work()
{
    while (qx.size())
    {
        ll nowX = qx.front();
        ll nowY = qy.front();
        ll nowT = qt.front();
        qx.pop();
        qy.pop();
        qt.pop();
        // if (dis[nowX][nowY] < nowT)
        //     continue;
        // cout << nowX << " " << nowY << " " << nowT << endl;
        if (val[nowX][nowY] != 0)
        {
            ans = ans + val[nowX][nowY] * nowT;
            val[nowX][nowY] = 0;
            // continue;
        }
        for (ll i = 0; i < 4; i++)
        {
            ll nextX = nowX + nx[i];
            ll nextY = nowY + ny[i];
            ll nextT = nowT + 1;
            if (nextX > n || nextX < 1 || nextY > n || nextY < 1)
                continue;
            if (val[nextX][nextY] == -1)
                continue;
            if (dis[nextX][nextY] <= nextT)
                continue;
            dis[nextX][nextY] = nextT;
            qx.push(nextX);
            qy.push(nextY);
            qt.push(nextT);
        }
    }
    cout << ans << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    init();
    work();
    return 0;
}