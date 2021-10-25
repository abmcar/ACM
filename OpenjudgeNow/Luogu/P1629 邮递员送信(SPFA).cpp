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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int dis[Maxn], ddis[Maxn];
bool inQueue[Maxn];
vector<int> g[Maxn], w[Maxn];
vector<int> gg[Maxn], ww[Maxn];
int ans;

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        w[t1].push_back(t3);
        gg[t2].push_back(t1);
        ww[t2].push_back(t3);
    }
    for (int i = 1; i <= n; i++)
        dis[i] = Inf;
}

void spfa()
{
    dis[1] = 0;
    inQueue[1] = true;
    queue<int> Q;
    Q.push(1);
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        inQueue[nowNode] = false;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            int nextDis = dis[nowNode] + w[nowNode][i];
            if (nextDis < dis[nextNode])
            {
                dis[nextNode] = nextDis;
                if (!inQueue[nextNode])
                {
                    Q.push(nextNode);
                    inQueue[nextNode] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ddis[i] = Inf, inQueue[i] = false;
    ddis[1] = 0;
    inQueue[1] = true;
    Q.push(1);
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        inQueue[nowNode] = false;
        for (int i = 0; i < gg[nowNode].size(); i++)
        {
            int nextNode = gg[nowNode][i];
            int nextDis = ddis[nowNode] + ww[nowNode][i];
            if (nextDis < ddis[nextNode])
            {
                ddis[nextNode] = nextDis;
                if (!inQueue[nextNode])
                {
                    Q.push(nextNode);
                    inQueue[nextNode] = true;
                }
            }
        }
    }
}

void output()
{
    for (int i = 2; i <= n; i++)
    {
        // cout << i << " " << dis[i] << " " << ddis[i] << endl;
        ans += dis[i] + ddis[i];
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    init();
    spfa();
    output();
    return 0;
}