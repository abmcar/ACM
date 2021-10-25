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
const ll Mod = 1e9 + 7;

int n, m, s;
vector<int> g[Maxn];
int fa[Maxn][23];
int deep[Maxn];
bool used[Maxn];

void dfs(int nowNode, int fatherNode)
{
    // cout << "nowNode: " << nowNode << endl;
    deep[nowNode] = deep[fatherNode] + 1;
    fa[nowNode][0] = fatherNode;
    used[nowNode] = true;
    for (int i = 1; (1 << i) <= deep[nowNode]; i++)
        fa[nowNode][i] = fa[fa[nowNode][i - 1]][i - 1];
    // cout << deep[nowNode] << " " << fa[nowNode][1] << endl;
    for (int i = 0; i < g[nowNode].size(); i++)
        if(!used[g[nowNode][i]])
        dfs(g[nowNode][i], nowNode);
}

int lca(int pos1, int pos2)
{
    if (deep[pos1] < deep[pos2])
        swap(pos1, pos2);
    // cout << pos1 << " " << pos2 << endl;
    while (deep[pos2] != deep[pos1])
    {
        // cout << deep[pos1] - deep[pos2] << " " << (int)log2(deep[pos1] - deep[pos2]) << endl;
        pos1 = fa[pos1][(int)log2(deep[pos1] - deep[pos2])];
    }
    // cout << "nextpos1: " << pos1 << endl;
    while (pos1 != pos2)
    {
        int nexti = 0;
        while (fa[pos1][nexti] != fa[pos2][nexti])
            nexti++;
        if (nexti != 0)
            nexti--;
        pos1 = fa[pos1][nexti];
        pos2 = fa[pos2][nexti];
    }
    return pos1;
}

int main()
{
    Buff;
    cin >> n >> m >> s;
    for (int i = 1; i <= n-1; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(s, 0);
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        cout << lca(t1, t2) << endl;
    }
    return 0;
}