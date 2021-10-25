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

int n, m, partyPos;
int dis[Maxn], ddis[Maxn];
bool inQ[Maxn];
vector<int> g[Maxn], w[Maxn];
vector<int> gg[Maxn], ww[Maxn];
int ans;

void spfa()
{
    for (int i = 1; i <= n; i++)
        dis[i] = Inf;
    queue<int> Q;
    Q.push(partyPos);
    dis[partyPos] = 0;
    inQ[partyPos] = true;
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        inQ[nowNode] = false;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            int nextDis = dis[nowNode] + w[nowNode][i];
            if (dis[nextNode] > nextDis)
            {
                dis[nextNode] = nextDis;
                if (!inQ[nextNode])
                {
                    Q.push(nextNode);
                    inQ[nextNode] = true;
                }
            }
        }
    }
}

void afps()
{
    for (int i = 1; i <= n; i++)
        ddis[i] = Inf, inQ[i] = false;
    queue<int> Q;
    Q.push(partyPos);
    ddis[partyPos] = 0;
    inQ[partyPos] = true;
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        inQ[nowNode] = false;
        for (int i = 0; i < gg[nowNode].size(); i++)
        {
            int nextNode = gg[nowNode][i];
            int nextDis = ddis[nowNode] + ww[nowNode][i];
            if (ddis[nextNode] > nextDis)
            {
                ddis[nextNode] = nextDis;
                if (!inQ[nextNode])
                {
                    Q.push(nextNode);
                    inQ[nextNode] = true;
                }
            }
        }
    }
}

int main()
{
    Buff;
    cin >> n >> m >> partyPos;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        w[t1].push_back(t3);
        gg[t2].push_back(t1);
        ww[t2].push_back(t3);
    }
    spfa();
    afps();
    for (int i = 1; i <= n; i++)
    {
        if (i == partyPos)
            continue;
        ans = max(ans,dis[i]+ddis[i]);
    }
    cout << ans;
    return 0;
}