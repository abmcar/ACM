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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e4 + 10;
const ll Mod = 1e9 + 7;

int n, m;
vector<int> g[Maxn];
bool vis[Maxn];
int maxDeep, deepNode;

void dfs(int nowNode, int deep)
{
    vis[nowNode] = true;
    cout << nowNode << " " << deep << Endl;
    if (deep > maxDeep)
    {
        maxDeep = deep;
        deepNode = nowNode;
    }
    for (int i = 0; i < g[nowNode].size(); i++)
    {
        int nextNode = g[nowNode][i];
        if (vis[nextNode])
            continue;
        dfs(nextNode, deep+1);
    }
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(1,0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "=[" << Endl;
            return 0;
        }
        vis[i] = false;
    }
    cout << deepNode << " " << maxDeep << endl;
    maxDeep = 0;
    dfs(deepNode,0);
    cout << deepNode << endl;
    cout << maxDeep << endl;
    return 0;
}