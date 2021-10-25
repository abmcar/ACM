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
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t;
ll n, m, x, y;
ll nx[8] = {1, -1, 2, 2, 1, -1, -2, -2};
ll ny[8] = {2, 2, 1, -1, -2, -2, 1, -1};
bool vis[99][99];
ll preAns[99][99];
ll ans;
int cnt;
ll dfs(ll nowX, ll nowY, ll nowDeep)
{
    cnt++;
    // cout << nowX << " " << nowY << " " << nowDeep << " " << preAns[nowX][nowY] << endl;
    // if (preAns[nowX][nowY] != 0)
    // {
    //     if (nowDeep + preAns[nowX][nowY]-2 < n * m)
    //         return 1;
    // }
    if (nowDeep == n * m)
    {
        ans++;
        // preAns[nowX][nowY] =
        return 1;
    }
    // if (preAns[nowX][nowY])
    //     return preAns[nowX][nowY];
    ll nowMax = 1;
    for (ll i = 0; i < 8; i++)
    {
        ll nextX = nowX + nx[i];
        ll nextY = nowY + ny[i];
        if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= m)
            continue;
        if (vis[nextX][nextY])
            continue;
        // if (preAns[nextX][nextY])
        // if (nowDeep + preAns[nextX][nextY]+n*m/2 < n*m)
        //     continue;
        vis[nextX][nextY] = true;
        // if (dfs(nextX, nextY, nowDeep + 1) == -1)
        //     nowMax = pre
        nowMax = max(nowMax, 1+dfs(nextX, nextY, nowDeep + 1));
        vis[nextX][nextY] = false;
    }
    // if (nowMax)
    //     nowMax++;
    preAns[nowX][nowY] = max(preAns[nowX][nowY], nowMax);
    return nowMax;
}

void work()
{
    // queue<ll> qX,qY,qN;
    cin >> n >> m >> x >> y;
    // x++;
    // y++;
    memset(vis, 0, sizeof vis);
    vis[x][y] = true;
    ans = 0;
    dfs(x, y, 1);
    cout << ans << endl;
    // cout << cnt << endl;
}

int main()
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