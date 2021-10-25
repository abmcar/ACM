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

ll n, m, b;
ll ans, l, r;
ll dis[Maxn];
ll cost[Maxn];
vector<int> g[Maxn], atk[Maxn];

bool check(int num)
{
    for (ll i = 1; i <= n; i++)
        dis[i] = Inf;
    queue<ll> qN, qH;
    qN.push(1);
    qH.push(0);
    dis[1] = 0;
    while (!qN.empty())
    {
        ll nowNode = qN.front();
        ll nowHealth = qH.front();
        // cout << nowNode << " " << nowHealth << " " << num << endl;
        qN.pop();
        qH.pop();
        for (int i = 0; i < g[nowNode].size(); i++)
        {
            if (cost[g[nowNode][i]] > num)
                continue;
            ll nextNode = g[nowNode][i];
            ll nextHealth = nowHealth + atk[nowNode][i];
            // cout << nextNode << " " << nextHealth << endl;
            if (nextHealth < dis[nextNode])
            {
                dis[nextNode] = nextHealth;
                qN.push(nextNode);
                qH.push(nextHealth);
            }
        }
    }
    // cout << dis[n] << endl;
    if (dis[n] == Inf || dis[n] >= b)
        return false;
    return true;
}

int main()
{
    Buff;
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++)
        cin >> cost[i], dis[i] = Inf, r = max(r,cost[i]);
    for (int i = 1; i <= m; i++)
    {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
        atk[t1].push_back(t3);
        atk[t2].push_back(t3);
    }
    // cout << l << ' ' << r << endl;
    while (l <= r)
    {
        // cout << l << " " << r << endl;
        ll mid = (l + r) / 2;
        // cout << "mid:" << mid << endl;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }

    if(ans == 0)
        cout << "AFK" << endl;
    else
        cout << ans;

    // if (dis[n] == Inf)
    //     cout << "AFK" << endl;
    // else
    //     cout << dis[n] << endl;
    return 0;
}