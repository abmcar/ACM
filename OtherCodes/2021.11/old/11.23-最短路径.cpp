#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e6 + 10;
const ll Mod = 2e9 + 7;

int n, m;
vector<int> g[Maxn], w[Maxn];
int dis[Maxn];
bool inQ[Maxn];
// int pre[Maxn];

struct Node
{
    int deep, node;
} pre[Maxn];

void spfa()
{
    for (int i = 0; i < n; i++)
        dis[i] = 2e9, pre[i].node = -1, pre[i].deep = 2e9;
    queue<int> qN;
    qN.push(0);
    dis[0] = 0;
    inQ[0] = true;
    while (!qN.empty())
    {
        int nowNode = qN.front();
        qN.pop();
        inQ[nowNode] = false;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            int nextDis = dis[nowNode] + w[nowNode][i];
            if (nextDis <= dis[nextNode])
            {
                dis[nextNode] = nextDis;
                if (inQ[nextNode])
                    continue;
                qN.push(nextNode);
                inQ[nextNode] = true;
            }
        }
    }
}

void bfs()
{
    queue<int> qN;
    qN.push(0);
    pre[0].deep = 1;
    while (!qN.empty())
    {
        int nowNode = qN.front();
        // cout << nowNode << endl;
        qN.pop();
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            int nextDis = dis[nowNode] + w[nowNode][i];
            if (nextDis != dis[nextNode])
                continue;
            qN.push(nextNode);
            if (pre[nextNode].node == -1)
            {
                pre[nextNode].node = nowNode;
                pre[nextNode].deep = pre[nowNode].deep + 1;
            }
            if (pre[nextNode].deep >= pre[nowNode].deep + 1)
            {
                if (pre[nextNode].deep > pre[nowNode].deep + 1)
                {
                    pre[nextNode].node = nowNode;
                    pre[nextNode].deep = pre[nowNode].deep + 1;
                }
                if (pre[nextNode].node > nowNode)
                {
                    pre[nextNode].node = nowNode;
                    pre[nextNode].deep = pre[nowNode].deep + 1;
                }
            }
        }
    }
}

void print(int node)
{
    if (pre[node].node == -1)
        return;
    stack<int> S;
    while (node != -1)
    {
        S.push(node);
        node = pre[node].node;
    }
    while (!S.empty())
    {
        cout << S.top();
        S.pop();
        if (!S.empty())
            cout << "->";
    }
    cout << endl;
}

signed main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        w[t1].push_back(t3);
    }
    spfa();
    bfs();
    for (int i = 1; i < n; i++)
        if (dis[i] != 2e9)
            print(i);
    return 0;
}
/* 
7 7
0 1 1
1 4 2
4 6 3
0 3 4
3 5 2
0 2 5
2 5 1



 */