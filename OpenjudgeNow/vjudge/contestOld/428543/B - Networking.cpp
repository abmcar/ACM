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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, m;
ll ans;
int father[Maxn];

struct Edge
{
    int from, to;
    ll val;
    bool const operator<(Edge b) const
    {
        return val > b.val;
    }
} edge[Maxn];

int find(int son)
{
    if (father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

int main()
{
    Buff;
    while (cin >> n && n)
    {
        priority_queue<Edge> q;
        cin >> m;
        ans = 0;
        for (int i = 1; i <= n; i++)
            father[i] = i;
        for (int i = 1; i <= m; i++)
        {
            Edge temp;
            cin >> temp.from >> temp.to >> temp.val;
            q.push(temp);
        }
        while (!q.empty())
        {
            Edge nowEdge = q.top();
            q.pop();
            int f1 = find(nowEdge.from);
            int f2 = find(nowEdge.to);
            if (f1 == f2)
                continue;
            father[f1] = f2;
            ans += nowEdge.val;
        }
        cout << ans << endl;
    }
    return 0;
}