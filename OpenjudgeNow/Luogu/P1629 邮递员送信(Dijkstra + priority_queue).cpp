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
bool used[Maxn];
vector<int> g[Maxn], w[Maxn];
vector<int> gg[Maxn], ww[Maxn];
int ans;

struct Node
{
    int pos, dis;
    bool const operator< (Node b) const
    {
        return dis > b.dis;
    }
};

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

void dijkstra()
{
    dis[1] = 0;
    priority_queue<Node> Q;
    Q.push({1,0});
    while (!Q.empty())
    {
        Node now = Q.top();
        Q.pop();
        int nowNode = now.pos;
        if (used[nowNode])
            continue;
        // cout << nowNode << endl;
        used[nowNode] = true;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextPos = g[nowNode][i];
            int nextDis = dis[nowNode] + w[nowNode][i];
            if (dis[nextPos] > nextDis)
            {
                dis[nextPos] = nextDis;
                if (used[nextPos])
                    continue;
                Q.push({nextPos,dis[nextPos]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ddis[i] = Inf, used[i] = false;
    ddis[1] = 0;
    Q.push({1,0});
    while (!Q.empty())
    {
        Node now = Q.top();
        Q.pop();
        int nowNode = now.pos;
        if (used[nowNode])
            continue;
        used[nowNode] = true;
        for (int i = 0; i < gg[nowNode].size(); i++)
        {
            int nextPos = gg[nowNode][i];
            int nextDis = ddis[nowNode] + ww[nowNode][i];
            if (ddis[nextPos] > nextDis)
            {
                ddis[nextPos] = nextDis;
                if (used[nextPos])
                    continue;
                Q.push({nextPos,ddis[nextPos]});
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
    dijkstra();
    output();
    return 0;
}