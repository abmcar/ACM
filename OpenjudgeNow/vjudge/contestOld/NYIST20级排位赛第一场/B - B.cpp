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
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n;
vector<int> g[Maxn];
int r1, r2;

int dfs(int nowNode, int fatherNode)
{
    int nowNum = 0;
    for (int i = 0; i < g[nowNode].size(); i++)
    {
        int nextNode = g[nowNode][i];
        if (fatherNode == nextNode)
            continue;
        nowNum += dfs(nextNode,nowNode);
    }
    if (nowNum == n/2)
    {
        r1 = nowNode;
        r2 = fatherNode;
    }
}

void work()
{
    r1 = r2 = -1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);   
        g[t2].push_back(t1);   
    }
    dfs(1,0);
    if (n % 2)
    {
        cout << "1 2" << endl;
        cout << "1 2" << endl;
        return;
    }
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}