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
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const ll Maxn = 1e6 + 10;
ll Mod = 1e9 + 7;

ll n, m, t, cnt;
ll num[Maxn];
struct Node
{
    ll l, r;
    ll val = 0;
} node[Maxn];

ll lSon(ll x)
{
    return x * 2;
}

ll rSon(ll x)
{
    return x * 2 + 1;
}

void pushUp(ll x)
{
    node[x].val = max(node[lSon(x)].val, node[rSon(x)].val);
}

void build(ll nowPos, ll nowL, ll nowR)
{
    node[nowPos].l = nowL;
    node[nowPos].r = nowR;
    if (nowL == nowR)
        return;
    ll nowMid = (nowL + nowR) / 2;
    build(lSon(nowPos), nowL, nowMid);
    build(rSon(nowPos), nowMid + 1, nowR);
}

void modify(ll nowPos, ll nowL, ll nowR, ll targetL, ll targetR, ll value)
{
    if (nowL >= targetL && nowR <= targetR)
    {
        node[nowPos].val = value;
        return;
    }
    ll nowMid = (nowL + nowR) / 2;
    if (nowMid >= targetL)
        modify(lSon(nowPos), nowL, nowMid, targetL, targetR, value);
    if (nowMid + 1 <= targetR)
        modify(rSon(nowPos), nowMid + 1, nowR, targetL, targetR, value);
    pushUp(nowPos);
}

ll query(ll nowPos, ll nowL, ll nowR, ll targetL, ll targetR)
{
    // cout << nowPos << " " << nowL << " " << nowR << " " << targetL << " " << targetR << endl;
    if (nowL >= targetL && nowR <= targetR)
        return node[nowPos].val;
    ll nowMid = (nowL + nowR) / 2;
    ll nowAns = 0;
    if (nowMid >= targetL)
        nowAns = max(nowAns, query(lSon(nowPos), nowL, nowMid, targetL, targetR));
    if (nowMid + 1 <= targetR)
        nowAns = max(nowAns, query(rSon(nowPos), nowMid + 1, nowR, targetL, targetR));
    return nowAns;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> m >> Mod;
    build(1, 1, m);
    for (ll i = 1; i <= m; i++)
    {
        char opt;
        ll value;
        cin >> opt >> value;
        // cout << opt << " " << value << " 1111" << endl;
        if (opt == 'A')
        {
            modify(1, 1, m, n + 1, n + 1, (value+cnt) % Mod);
            n++;
        }
        else
        {
            cnt = query(1, 1, m, n - value + 1, n);
            cout << cnt << endl;
        }
    }
    return 0;
}