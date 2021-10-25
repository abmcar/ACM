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

int n, m;
int dis[Maxn];
bool inQ[Maxn];
vector<int> g[Maxn], w[Maxn];

int main()
{
    Buff;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        dis[i] = Inf;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
        w[t1].push_back(t3);
        w[t2].push_back(t3);
    }
    queue<int> Q;
    Q.push(n);
    dis[n] = 0;
    inQ[n] = true;
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
    cout << dis[1] << endl;
    return 0;
}