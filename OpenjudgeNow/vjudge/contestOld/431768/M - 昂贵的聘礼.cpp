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

const int Maxn = 1e5;
const ll Mod = 1e9 + 7;

int m, n, ans = 1e9;
int level[Maxn], cost[Maxn], dis[Maxn];
bool inQ[Maxn];
int minn = 1e9;
int maxn = 0;
map<int, bool> ok;
vector<int> g[Maxn], w[Maxn];

void init()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e9;
        int tempn;
        cin >> cost[i] >> level[i] >> tempn;
        minn = min(minn, level[i]);
        maxn = max(maxn, level[i]);
        for (int j = 1; j <= tempn; j++)
        {
            int t, v;
            cin >> t;
            cin >> v;
            // scanf("%d %d", &t, &v);
            g[i].push_back(t);
            w[i].push_back(v);
        }
    }
}

void spfa()
{
    for (int i = 1; i <= n; i++)
        dis[i] = 1e9, inQ[i] = false;
    queue<int> Q;
    queue<int> EX;
    EX.push(0);
    Q.push(1);
    dis[1] = cost[1];
    while (!Q.empty())
    {
        int nowNode = Q.front();
        int nowEX = EX.front();
        Q.pop();
        EX.pop();
        // cout << nowNode << " " << nowEX << endl;
        inQ[nowNode] = false;
        ans = min(ans, dis[nowNode]);
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            int nextDis = nowEX + cost[nextNode] + w[nowNode][i];
            int nextLevel = level[nextNode];
            // ans = min(ans,dis[nextNode]);
            if (ok[nextNode] == false)
                continue;
            if (nextDis <= dis[nextNode])
            {
                dis[nextNode] = nextDis;
                if (!inQ[nextNode])
                {
                    inQ[nextNode] = true;
                    Q.push(nextNode);
                    // cout << nowNode << " " << nextNode << " " << nowEX + w[nowNode][i] << endl;
                    EX.push(nowEX + w[nowNode][i]);
                }
            }
        }
    }
}

void work()
{
    if (m == 0)
    {
        for (int i = 1; i <= n; i++)
            ok[i] = true;
        spfa();
        cout << ans << endl;
        return;
    }
    for (int i = level[1] - m; i <= level[1]; i++)
    {
        for (int j = 1; j <= n; j++)
            ok[j] = false;
        for (int j = 1; j <= n; j++)
            if (level[j] >= i && level[j] <= i + m)
                ok[j] = true;
        // cout << i << " " << i+m << endl;
        // cout << "pass#1" << endl;
        spfa();
    }
    cout << ans << endl;
}

int main()
{
    // Buff;
    init();
    work();
    return 0;
}