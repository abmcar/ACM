#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <string>
//#define int long long
#define ll long long
//#define x first
//#define y second
#define all(v) v.begin(), v.end()
#define mem(x, y) memset(x, y, sizeof(x))
#define debug1(x) cout << "*****" << x << endl;
#define debug() cout << "**" << endl;
#define debug2(x, y) cout << "*****" << x << " " << y << endl;
#define rb ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const ll mod = 998244353;
struct graph
{
    int head[5000050], _cnt = 0;
    int nex[5000050], to[5000050], w[5000050];
    graph()
    {
        mem(head, -1);
    }
    void add(int x, int y, int w1)
    {
        nex[_cnt] = head[x];
        w[_cnt] = w1;
        to[_cnt] = y;
        head[x] = _cnt++;
    }
} p;
struct Unionfind
{
    int f[500005];
    Unionfind()
    {
        for (int i = 1; i <= 100005; i++)
            f[i] = i;
    }
    int find(int x)
    {
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    void list(int x, int y)
    {
        int xx = find(f[x]);
        int yy = find(f[y]);
        f[xx] = yy;
    }
} g;
int w[100005];
vector<int> v[100005];
struct node
{
    int w, id;
};
int vis[100005];
int dep[100005];
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    for (int i = p.head[u]; ~i; i = p.nex[i])
    {
        int j = p.to[i];
        if (j == fa)
            continue;
        dfs(j, u);
    }
}
int cmp(node a, node b)
{
    return a.w < b.w;
}
signed main()
{
    //	freopen("P4315_1.in","r",stdin);
    //	freopen("test.out","w",stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            v[i].clear();
            vis[i] = 0;
            g.f[i] = i;
            p.head[i] = -1;
        }
        vector<node> v1;
        for (int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            v1.push_back({x, i});
        }
        sort(all(v1), cmp);
        for (int i = 0; i < v1.size(); i++)
        {
            vis[v1[i].id] = 1;
            for (auto j : v[v1[i].id])
            {
                if (vis[j])
                {
                    int pp = g.find(j);
                    g.list(j, v1[i].id);

                    //					debug2(pp,v1[i].id)
                    p.add(v1[i].id, pp, 0);
                    p.add(pp, v1[i].id, 0);
                }
            }
        }
        dfs(v1[v1.size() - 1].id, -1);
        for (int i = 1; i <= n; i++)
        {
            printf("%d\n", dep[i]);
        }
    }
}