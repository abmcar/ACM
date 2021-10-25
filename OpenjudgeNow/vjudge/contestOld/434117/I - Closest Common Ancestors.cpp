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

const int Maxn = 2e5 + 10;
const ll Mod = 1e9 + 7;

int n, m, t;
bool vised[Maxn];
int deep[Maxn];
int fa[Maxn][32];
map<int,int> ans;
vector<int> g[Maxn], w[Maxn];

void dfs(int nowNode, int fatherNode)
{
    // cout << nowNode << endl;
    deep[nowNode] = deep[fatherNode] + 1;
    vised[nowNode] = true;
    fa[nowNode][0] = fatherNode;
    for (int i = 1; (1 << i) <= deep[nowNode]; i++)
        fa[nowNode][i] = fa[fa[nowNode][i - 1]][i - 1];
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
    // cin >> n;
    ans.clear();
    for (int i = 1; i <= n; i++)
        vised[i] = false, deep[i] = 0, g[i].clear(), w[i].clear();
    map<int,int> M;
    for (int i = 1; i <= n; i++)
    {
        int nowNode, nowNum;
        // scanf("%d:(%d)",&nowNode,&nowNum);
        cin >> nowNode;
        char tempChar;
        cin >> tempChar >> tempChar >> nowNum >> tempChar;
        for (int j = 1; j <= nowNum; j++)
        {
            int temp;
            cin >> temp;
            g[nowNode].push_back(temp);
            M[temp]++;
        }
    }
    // cout << "pass1" << endl;
    for (int i = 1; i <= n; i++)
        if (M[i] == 0)
        {
            // cout << i << endl;
            dfs(i, 0);
            break;
        }
    // cout << "pass2" << endl;
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
        int t1, t2;
        char tempChar;
        cin >> tempChar >> t1 >> t2 >> tempChar;
        // scanf(" (%d %d)",&t1,&t2);
        int fa = lca(t1, t2);
        ans[fa]++;
    }
    for (map<int,int>::iterator it = ans.begin(); it != ans.end(); it++)
        cout << it->first << ":" << it->second << endl;
}

int main()
{
    Buff;
    while (cin >> n)
        work();
    return 0;
}