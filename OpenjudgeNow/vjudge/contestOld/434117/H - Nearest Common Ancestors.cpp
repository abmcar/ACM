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

const int Maxn = 2e4 + 10;
const ll Mod = 1e9 + 7;

int n, m, t;
bool vised[Maxn];
int deep[Maxn];
int fa[Maxn][32];
int father[Maxn];
vector<int> g[Maxn];

void dfs(int nowNode, int fatherNode)
{
    // cout << nowNode << endl;
    deep[nowNode] = deep[fatherNode] + 1;
    fa[nowNode][0] = fatherNode;
    for (int i = 1; (1 << i) <= deep[nowNode]; i++)
        fa[nowNode][i] = fa[fa[nowNode][i - 1]][i - 1];
    // cout << "pass2" << endl;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            dfs(nextNode, nowNode);
        }
}

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        vised[i] = false, deep[i] = 0, g[i].clear(), father[i] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2;
        father[t2] = t1;
    }
    // int str = 1;
    // while (M[str] != 0)
    //     str = M[str];
    // dfs(str,0);
    // for (int i = 1; i <= n; i++)
    // {
    //     // cout << "test:" << i << endl;
    //     if(M[i] == 0)
    //     {
    //         dfs(i, 0);
    //         break;
    //     }
    // }
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
        // cout << c1 << " " << c2 << " " << nexti << endl;
    }
    return c1;
}

void work()
{
    init();
    int t1, t2;
    cin >> t1 >> t2;
    while (t1)
    {
        // cout << t1 << endl;
        vised[t1] = true;
        t1 = father[t1];
    }
    while (t2)
    {
        if (vised[t2])
            break;
        t2 = father[t2];
    }
    cout << t2 << endl;
}

int main()
{
    // Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}