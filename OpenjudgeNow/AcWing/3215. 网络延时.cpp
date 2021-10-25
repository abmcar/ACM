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
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 4e4 + 10;
const ll Mod = 1e9 + 7;

int n, m, maxDeep, deepNode;
vector<int> g[Maxn];

void dfs(int nowNode, int nowDeep, int fatherNode)
{
    // cout << nowNode << " " << nowDeep << Endl;
    if (nowDeep > maxDeep)
    {
        maxDeep = nowDeep;
        deepNode = nowNode;
    }
    for (auto nextNode : g[nowNode])
    {
        if (nextNode == fatherNode)
            continue;
        dfs(nextNode, nowDeep + 1, nowNode);
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
    for (int i = 2; i <= n; i++)
    {
        int t1, t2;
        cin >> t1;
        t2 = i;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1;
        t2 = i + n;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    // for (int i = 1; i <= n+m; i++)
    // {
    //     cout << i << ' ';
    //     for (auto nowNode : g[i])
    //         cout << nowNode << " ";
    //     cout << endl;
    // }
    dfs(1, 0, 0);
    maxDeep = 0;
    dfs(deepNode, 0, 0);
    cout << maxDeep << endl;
    return 0;
}