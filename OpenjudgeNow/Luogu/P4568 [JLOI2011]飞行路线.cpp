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

int n, m, k;
int s, t;
vector<int> g[Maxn];
vector<int> w[Maxn];
int pre[Maxn];
int dis[Maxn][20];
bool vised[Maxn][20];
int ans = 1e9;

inline void spfa()
{
    queue<int> qN, qK;
    qN.push(s);
    qK.push(k);
    vised[s][k] = true;
    dis[s][k] = 0;
    while (!qN.empty())
    {
        int nowNode = qN.front();
        int nowK = qK.front();
        qN.pop();
        qK.pop();
        vised[nowNode][nowK] = false;
        if (nowNode == t)
        {
            ans = min(ans, dis[nowNode][nowK]);
            continue;
        }
        if (dis[nowNode][nowK] >= ans)
            continue;
        // cout << nowNode << " " << nowK << endl;
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            int nextNode = g[nowNode][i];
            int nextCost = dis[nowNode][nowK] + w[nowNode][i];
            if (nextCost < dis[nextNode][nowK] && nextCost <= ans)
            {
                dis[nextNode][nowK] = nextCost;
                if (!vised[nextNode][nowK])
                {
                    qN.push(nextNode);
                    qK.push(nowK);
                    vised[nextNode][nowK] = true;
                }
            }
            if (nowK > 0)
                if (dis[nowNode][nowK] < dis[nextNode][nowK - 1])
                {
                    dis[nextNode][nowK - 1] = dis[nowNode][nowK];
                    if (!vised[nextNode][nowK - 1])
                    {
                        qN.push(nextNode);
                        qK.push(nowK - 1);
                        vised[nextNode][nowK - 1] = true;
                    }
                }
        }
    }
}

int main()
{
    Buff;
    cin >> n >> m >> k;
    cin >> s >> t;
    s++;
    t++;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dis[i][j] = Inf;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        t1++;
        t2++;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
        w[t1].push_back(t3);
        w[t2].push_back(t3);
    }
    spfa();
    cout << ans;
    return 0;
}