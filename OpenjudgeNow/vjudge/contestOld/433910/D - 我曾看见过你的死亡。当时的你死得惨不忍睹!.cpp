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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int father[Maxn];

struct Edge
{
    int from, to, val;
    bool const operator< (Edge b) const
    {
        return val > b.val;
    }
    bool ok;
}edges[Maxn];

int find(int son)
{
    if (son == father[son])
        return son;
    father[son] = find(father[son]);
    return father[son];
}

int main()
{
    // Buff;
    cin >> n >> m;
    // cout << "pass-2" << endl;
    for (int i = 1; i <= n; i++)
        father[i] = i;
    priority_queue<Edge> Q;
    int minn = 1e9;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        edges[i].from = t1;
        edges[i].to = t2;
        edges[i].val = t3;
        edges[i].ok = true;
        minn = min(t3,minn);
        Q.push(edges[i]);
    }
    // cout << "pass-1" << endl;
    int ans1 = 0;
    int ans2 = 1e9;
    while (!Q.empty())
    {
        Edge nowEdge = Q.top();
        Q.pop();
        int f1 = find(nowEdge.from);
        int f2 = find(nowEdge.to);
        if (f1 == f2)
            continue;
        father[f1] = f2;
        ans1 += nowEdge.val;
    }
    // cout << "pass0" << endl;
    bool ok = true;
    for (int j = 2; j <= n; j++)
        if (find(j) != find(1))
            ok = false;
    if (!ok)
    {
        cout << "Cost: -1" << endl;
        cout << "Cost: -1" << endl;
        return 0;
    }
    // cout << "pass1" << endl;
    for (int i = 1; i <= m; i++)
    {
        // if (edges[i].val == minn)
        {
            int nowans = 0;
            for (int j = 1; j <= m; j++)
            {
                if (i == j)
                    continue;
                Q.push(edges[j]);
            }
            for (int j = 1; j <= n; j++)
                father[j] = j;
            while (!Q.empty())
            {
                Edge nowEdge = Q.top();
                Q.pop();
                int f1 = find(nowEdge.from);
                int f2 = find(nowEdge.to);
                if (f1 == f2)
                    continue;
                father[f1] = f2;
                nowans += nowEdge.val;
            }
            bool ok = true;
            for (int j = 2; j <= n; j++)
                if (find(j) != find(1))
                    ok = false;
            if (ok)
            ans2 = min(nowans,ans2);
        }
    }
    if (ans2 == 0)
        ans2 = 1e9;
    cout << "Cost: " << ans1 << endl;
    cout << "Cost: " << ans2;
    return 0;
}