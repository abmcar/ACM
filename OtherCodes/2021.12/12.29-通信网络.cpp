#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3 + 10;

int n, m;
struct Edge
{
    int form, to, val;
    bool operator<(Edge b) const
    {
        return val < b.val;
    }
};
int bd[Maxn][Maxn];
int father[Maxn];
int rd[Maxn];
vector<int> g[Maxn];
vector<int> w[Maxn];
vector<Edge> edges;

int find(int son)
{
    if (son == father[son])
        return son;
    father[son] = find(father[son]);
    return father[son];
}

void get()
{
    cout << "输入点数和边数" << endl;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            bd[i][j] = 1e9;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cout << "输入第" << i << "条边的起点，终点和距离"  << endl;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
        w[t1].push_back(t3);
        w[t2].push_back(t3);
        edges.push_back({t1, t2, t3});
        bd[t1][t2] = bd[t2][t1] = t3;
        rd[t2]++;
    }
}

void kruskal()
{
    int nowTime = clock();
    int nowAns = 0;
    sort(edges.begin(), edges.end());
    for (auto it : edges)
    {
        int f1 = find(it.form);
        int f2 = find(it.to);
        if (f1 == f2)
            continue;
        father[f1] = f2;
        nowAns += it.val;
    }
    cout << "Kruskal time cost: " << clock() - nowTime << endl;
    cout << "Kruskal ans: " << nowAns << endl;
}

void prim()
{
    int nowTime = clock();
    int nowAns = 0;
    map<int, int> dist;
    map<int, bool> ok;
    for (int i = 1; i <= n; i++)
        dist[i] = 1e9;
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (ok[j] == false && (t == -1 || dist[j] < dist[t]))
                t = j;
        nowAns += dist[t];
        ok[t] = true;
        dist[t] = 0;
        for (int j = 0; j < g[t].size(); j++)
        {
            int nextNode = g[t][j];
            dist[nextNode] = min(dist[nextNode], w[t][j]);
        }
    }
    cout << "Prim time cost: " << clock() - nowTime << endl;
    cout << "Prim ans: " << nowAns << endl;
}

void floyed()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                bd[i][j] = min(bd[i][j], bd[i][k] + bd[k][j]);
    cout << "min dis:" << endl;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            cout << i << "-"
                 << j << ":" << bd[i][j] << endl;
}

void topsort()
{
    queue<int> nowQ;
    for (int i = 1; i <= n; i++)
        if (rd[i] == 0)
            nowQ.push(i), rd[i]--;
    cout << "Topsort:";
    while (!nowQ.empty())
    {
        int nowNode = nowQ.front();
        nowQ.pop();
        cout << nowNode << " ";
        for (auto it : g[nowNode])
        {
            rd[it]--;
            if (rd[it] == 0)
                nowQ.push(it);
        }
    }
    cout << endl;
}

int main()
{
    get();
    kruskal();
    prim();
    floyed();
    topsort();
    return 0;
}

/* 
3 3
1 2 1 
2 3 2 
1 3 3


 */