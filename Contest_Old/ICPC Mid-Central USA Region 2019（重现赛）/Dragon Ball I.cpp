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
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>               
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, m;
vector<int> g[Maxn], w[Maxn];
vector<int> targets;
map<int,bool> M;
int ans;
int eachDis[10][10];
int finAns;
bool vis[Maxn];

int spfa(int strNode, int targetNode)
{
    queue<int> qN;
    qN.push(strNode);
    unordered_map<int, int> dis;
    unordered_map<int, bool> inQ;
    for (int i = 1; i <= n; i++)
        dis[i] = 2e9;
    inQ[strNode] = true;
    dis[strNode] = 0;
    while (!qN.empty())
    {
        int nowNode = qN.front();
        qN.pop();
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            int nextDis = dis[nowNode] + w[nowNode][i];
            if (nextDis < dis[nextNode])
            {
                dis[nextNode] = nextDis;
                if (!inQ[nextNode])
                    qN.push(nextNode);
            }
        }
    }
    return dis[targetNode];
}

void dfs(int nowNode, int nowAns, int deep)
{
    // cout << nowNode << " " << nowAns << " " << deep << endl;
    if (deep == targets.size())
        finAns = min(finAns, nowAns);
    for (int i = 0; i < targets.size(); i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        dfs(i, nowAns + eachDis[nowNode][i], deep + 1);
        vis[i] = false;
    }
}

int main()
{
    Buff;
    char * test = NULL;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    finAns = 2e9;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
        w[t1].push_back(t3);
        w[t2].push_back(t3);
    }
    for (int i = 1; i <= 7; i++)
    {
        int temp;
        cin >> temp;
        // if (temp == 1)
        //     continue;
        if (M[temp])
            continue;
        M[temp] = true;
        targets.push_back(temp);
    }
    bool tt = false;
    if (!M[1])
        targets.push_back(1), tt = true;
    // cout << targets.size() << endl;
    for (int i = 0; i < targets.size(); i++)
        for (int j = i + 1; j < targets.size(); j++)
            eachDis[i][j] = eachDis[j][i] = spfa(targets[i], targets[j]);
    // vis[1] = true;
    if (!tt)
        dfs(1,0,0);
    else
        dfs(1,0,1);
    cout << finAns << endl;
    return 0;
}                              