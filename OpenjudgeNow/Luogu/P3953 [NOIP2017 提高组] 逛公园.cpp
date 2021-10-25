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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m, d, k;
int dis[Maxn];
vector<int> g[Maxn], w[Maxn];

void spfa()
{
    queue<int> Q;
    Q.push(1);
    dis[1] = 0;
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        // cout << nowNode << endl;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            if(dis[nextNode] > dis[nowNode] + w[nowNode][i])
            {
                dis[nextNode] = dis[nowNode] + w[nowNode][i];
                Q.push(nextNode);
            }
        }
    }
    d = dis[n];
}

void work()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dis[i] = Inf;
    for (int i = 1; i <= m; i++)
    {
        int ta, tb, tc;
        cin >> ta >> tb >> tc;
        g[ta].push_back(tb);
        g[tb].push_back(ta);
        w[ta].push_back(tc);
        w[tb].push_back(tc);
    }
    spfa();
    cout << d << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}