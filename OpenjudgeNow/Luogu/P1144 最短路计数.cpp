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
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e5+10;
const ll Mod = 100003;

int n, m;
int dis[Maxn];
int ans[Maxn];
vector<int> g[Maxn];
bool inQueue[Maxn];

int main()
{
    Buff;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int ta, tb;
        cin >> ta >> tb;
        g[ta].push_back(tb);
        g[tb].push_back(ta);
    }
    for (int i = 1; i <= n; i++)
        dis[i] = Inf;
    queue<int> Q;
    dis[1] = 0;
    inQueue[1] = true;
    Q.push(1);
    ans[1] = 1;
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        inQueue[nowNode] = false;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            if (dis[nextNode] > dis[nowNode] + 1)
            {
                dis[nextNode] = dis[nowNode] + 1;
                ans[nextNode] = ans[nowNode];
                if(!inQueue[nextNode])
                    Q.push(nextNode);
                continue;
            }
            if (dis[nextNode] == dis[nowNode] + 1)
                ans[nextNode] += ans[nowNode] % Mod;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i]%Mod << endl;
    return 0;
}