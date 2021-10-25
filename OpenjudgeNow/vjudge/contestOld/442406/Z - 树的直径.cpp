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

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int n;
vector<int> g[Maxn];
int nowMaxDeep, deepNode;

void dfs(int nowNode, int fatherNode, int deep)
{
    if (nowMaxDeep < deep)
    {
        nowMaxDeep = deep;
        deepNode = nowNode;
    }
    for (auto i : g[nowNode])
    {
        if (i == fatherNode)
            continue;
        dfs(i,nowNode,deep+1);
    }
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n-1; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(1,0,1);
    nowMaxDeep = 0;
    dfs(deepNode,0,1);
    cout << nowMaxDeep-1 << endl;
    return 0;
}