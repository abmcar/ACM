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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int n, m, t;
int dis[Maxn];
bool inQ[Maxn];
vector<int> g[Maxn], w[Maxn];
int cnt;

void spfa()
{
    queue<int> Q;
    Q.push(1);
    dis[1] = 1e9;
    // dis[1] = 0;
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        inQ[nowNode] = false;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            double nextDis = min(dis[nowNode],w[nowNode][i]);
            if (dis[nextNode] < nextDis)
            {
                dis[nextNode] = nextDis;
                if (!inQ[nextNode])
                {
                    inQ[nextNode] = true;
                    Q.push(nextNode);
                }
            }
        }
    }
}

void work()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        dis[i] = 0, g[i].clear(), w[i].clear();
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
        w[t1].push_back(t3);
        w[t2].push_back(t3);
    }
    spfa();
    cout << "Scenario #" << ++cnt << ":" << endl;
    cout << dis[n] << endl << endl;
}

int main()
{
    Buff;
    cin >> t;
    while (t--)
        work();
}