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

using namespace std;

const int Maxn = 2e5 + 10;
const ll Mod = 1e9 + 7;

int n, p;
int sTime[Maxn], eTime[Maxn], nowTime;
int ans[Maxn];
vector<int> g[Maxn];

int lowbit(int x)
{
    return x & (-x);
}

void update(int x)
{
    // cout << "u " << x << endl;
    while(x <= n)
    {
        ans[x] += 1;
        x += lowbit(x);
    }
}

int query(int x)
{
    // cout << "q " << x << endl; 
    int res = 0;
    while (x != 0)
    {
        res += ans[x];
        x = x - lowbit(x);
    }
    return res;
}

void dfs(int nowNode, int fatherNode)
{
    nowTime++;
    sTime[nowNode] = nowTime;
    for (int i = 0; i < g[nowNode].size(); i++)
    {
        int nextNode= g[nowNode][i];
        if (nextNode == fatherNode)
            continue;
        dfs(nextNode, nowNode);
    }
    eTime[nowNode] = nowTime;
}

void work()
{
    nowTime = 0;
    for (int i = 1; i <= 1e5; i++)
        g[i].clear(), ans[i] = 0;
    for (int i = 2; i <= n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(p,0);
    for (int i = 1; i < n; i++)
    {
        cout << query(eTime[i]) - query(sTime[i]) << " ";
        update(sTime[i]);
    }
    cout << query(eTime[n]) - query(sTime[n]) << endl;
}

int main()
{
    Buff;
    while (cin >> n >> p)
    {
        if (n + p == 0)
            break;
        work();
    }
    return 0;
}