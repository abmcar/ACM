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
using namespace __gnu_pbds;

const ll Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

ll t,n;
ll w[Maxn];
ll p[Maxn][Maxn];
ll father[Maxn];
bool ok[Maxn];
int find(int son)
{
    if (father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

struct Edge
{
    int from, to, val;
    const bool operator< (Edge b) const
    {
        return val > b.val;
    }
};

void work()
{
    std::priority_queue<Edge> Q;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i], father[i] = i, ok[i] = false;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
        cin >> p[i][j];
        if (i != j)
        {
            Edge edge;
            edge.from = i;
            edge.to = j;
            edge.val = p[i][j];
            // edge[]
            Q.push(edge);
        }else
        {
            Edge edge;
            edge.from = edge.to = i;
            edge.val = w[i];
            Q.push(edge);
        }
    }
    ll cost = 0;
    while (!Q.empty())
    {
        Edge nowEdge = Q.top();
        Q.pop();
        if (nowEdge.from == nowEdge.to)
        {
            int fa = find(nowEdge.from);
            if (ok[fa])
                continue;
            cost += nowEdge.val;
            ok[fa] = true;
            // cout << nowEdge.from << " " << fa << endl;
            continue;
        }
        int f1 = find(nowEdge.from);
        int f2 = find(nowEdge.to);
        if (f1 == f2)
            continue;
        int nowCost = nowEdge.val;
        if (ok[f1] && ok[f2])
            continue;
        if (!ok[f1] && !ok[f2])
        {
            cost += nowCost;
            father[f1] = f2;
            continue;
        }
        father[f1] = f2;
        ok[f2] = true;
        cost += nowCost;
    }
    cout << cost << Endl;
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