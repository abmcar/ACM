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

int t, n, m, q;
int dis[Maxn], level[Maxn], updata[Maxn];
int finDis[Maxn];
bool inQ[Maxn];
vector<int> g[Maxn], w[Maxn];
int cnt;

bool spfa()
{
    queue<int> Q;
    Q.push(1);
    dis[1] = 0;
    while (!Q.empty())
    {
        int nowNode = Q.front();
        Q.pop();
        inQ[nowNode] = false;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            int nextDis = dis[nowNode] + w[nowNode][i];
            if (nextDis < dis[nextNode])
            {
                dis[nextNode] = nextDis;
                // if (dis[nextNode] > 3)
                //     finDis[nextNode] = min(finDis[nextNode], dis[nextNode]);
                if (!inQ[nextNode])
                {
                    inQ[nextNode] = true;
                    updata[nextNode]++;
                    if (updata[nextNode] >= n)
                        continue;
                    Q.push(nextNode);
                }
            }
        }
    }
}

void work()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        w[i].clear();
        cin >> level[i];
        dis[i] = 1e9;
        inQ[i] = false;
        updata[i] = 0;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        int nowW = pow((level[t2]-level[t1]),3);
        // if (nowW < 0)
        //     nowW *= -1;
        g[t1].push_back(t2);
        // g[t2].push_back(t1);
        w[t1].push_back(nowW);
        // w[t2].push_back(nowW);
    }
    spfa();
    cin >> q;
    cout << "Case " << ++cnt << ":" << endl;
    for (int i = 1; i <= q; i++)
    {
        int tempQuery;
        cin >> tempQuery;
        if (dis[tempQuery] == 1e9 || dis[tempQuery] < 3)
            cout << "?" << endl;
        else
            cout << dis[tempQuery] << endl;
    }
}

int main()
{
    Buff;
    // freopen("O.out","w",stdout);
    cin >> t;
    while (t--)
        work();
    return 0;
}