#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int Maxn = 1e3;

int n, m, finAns;
int dis[Maxn][Maxn];
int vis[Maxn];

void preWork()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = -1;
}

void dfs(int nowNode, int deep, int father)
{
    if (vis[nowNode])
        return;
    vis[nowNode] = 1;
    if (nowNode != 1)
        cout << ",";
    cout << nowNode;
    if (deep == n)
        return;
    for (int i = 1; i <= n; i++)
    {
        if (father == i)
            continue;
        if (vis[i] || dis[nowNode][i] == -1)
            continue;
        dfs(i, deep + 1, nowNode);
    }
}

void bfs()
{
    int finAns = 1e9;
    queue<int> Q, V, D;
    Q.push(1);
    V.push(0);
    D.push(1);
    // unordered_map<int, bool> M;
    bool M[Maxn];
    memset(M, 0, sizeof M);
    while (!Q.empty())
    {
        int nowNode = Q.front();
        int nowValue = V.front();
        int nowDeep = D.front();
        Q.pop();
        V.pop();
        D.pop();
        if (M[nowNode] == 0)
        {
            if (nowNode != 1)
                cout << ",";
            cout << nowNode;
            M[nowNode] = true;
        }
        else
            continue;
        if (nowNode == n)
        {
            finAns = min(finAns, nowValue);
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (dis[nowNode][i] == -1)
                continue;
            Q.push(i);
            V.push(nowValue + dis[nowNode][i]);
            D.push(nowDeep + 1);
        }
    }
    // cout << endl;
}

int spfa()
{
    memset(vis, 0, sizeof vis);
    queue<int> Qn;
    bool nowDis[Maxn], inQ[Maxn];
    memset(nowDis, 0, sizeof nowDis);
    memset(inQ, 0, sizeof inQ);
    for (int i = 1; i <= n; i++)
        nowDis[i] = 1e9;
    Qn.push(1);
    nowDis[1] = 0;
    inQ[1] = 1;
    vis[1] = true;
    while (!Qn.empty())
    {
        int nowNode = Qn.front();
        int nowValue = nowDis[nowNode];
        Qn.pop();
        for (int i = 1; i <= n; i++)
        {
            if (dis[nowNode][i] == -1 || vis[i])
                continue;
            if (nowDis[i] > nowValue + dis[nowNode][i])
            {
                nowDis[i] = nowValue + dis[nowNode][i];
                if (inQ[i])
                    continue;
                Qn.push(i);
            }
        }
    }
    return nowDis[n];
}

int main()
{
    cout << "Input" << endl;
    scanf("%d,%d", &n, &m);
    // cin >> n >> m;
    preWork();
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        // cin >> t1 >> t2 >> t3;
        scanf("%d,%d,%d", &t1, &t2, &t3);
        dis[t1][t2] = t3;
        dis[t2][t1] = t3;
    }
    cout << "Output" << endl;
    bfs();
    cout << endl;
    dfs(1, 1, 0);
    cout << endl;
    finAns = spfa();
    if (finAns == 1e9)
        finAns = 0;
    cout << finAns << endl;
    cout << "End";
    system("pause");
    return 0;
}