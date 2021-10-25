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

const int Maxn = 1e6 + 10;
const ll Mod = 998244353;

ll n, m, t;
bool vised[Maxn];
ll deep[Maxn];
ll fa[Maxn][32];
ll pre[Maxn][55];
vector<int> g[Maxn], w[Maxn];

ll quickPow(ll base, ll x)
{
    // cout << "qp\n";
    ll now = 1;
    while (x != 0)
    {
        if (x % 2 == 1)
        {
            x--;
            now = now * base % Mod;
        }
        base = base * base % Mod;
        x = x / 2;
    }
    return now;
}

void dfs(int nowNode, int fatherNode)
{
    deep[nowNode] = deep[fatherNode] + 1;
    vised[nowNode] = true;
    fa[nowNode][0] = fatherNode;
    for (int i = 1; i <= 50; i++)
        pre[nowNode][i] = pre[fatherNode][i] + quickPow(deep[nowNode],i);
    // cout << "fin qp\n";
    for (int i = 1; (1 << i) <= deep[nowNode]; i++)
        fa[nowNode][i] = fa[fa[nowNode][i - 1]][i - 1];
    // cout << "fin qp1\n";
    for (int i = 0; i < g[nowNode].size(); i++)
    {
        int nextNode = g[nowNode][i];
        if (vised[nextNode])
            continue;
        dfs(nextNode, nowNode);
    }
}

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        vised[i] = false, deep[i] = 0, g[i].clear(), w[i].clear();
    for (int i = 2; i <= n; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    deep[0] = -1;
    // cout << "input finish!" << endl;
    dfs(1, 0);
}

int lca(int c1, int c2)
{
    if (deep[c1] < deep[c2])
        swap(c1, c2);
    while (deep[c1] != deep[c2])
        c1 = fa[c1][(int)log2(deep[c1]-deep[c2])];
    while (c1 != c2)
    {
        int nexti = 0;
        while (fa[c1][nexti] != fa[c2][nexti])
            nexti++;
        if (nexti != 0)
            nexti--;
        c1 = fa[c1][nexti];
        c2 = fa[c2][nexti];
    }
    return c1;
}

void work()
{
    init();
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        int Lca = lca(t1, t2);
        // cout << " " << fa << endl;
        ll nowDis = pre[t1][t3] + pre[t2][t3] - (pre[Lca][t3] % Mod + pre[fa[Lca][0]][t3] % Mod) % Mod;
        nowDis = nowDis % Mod;
        cout << nowDis << endl;
    }
}

int main()
{
    Buff;
    work();
    // cout << pre[4][1] << endl << pre[3][1] << endl;
    return 0;
}