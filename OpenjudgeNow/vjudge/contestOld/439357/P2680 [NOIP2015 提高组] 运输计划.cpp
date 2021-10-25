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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf ll_MAX
#define endl "\n"

using namespace std;

const ll Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

ll n, m;
ll father[Maxn][32], deep[Maxn], val[Maxn], dis[Maxn];
ll sum[Maxn], d[Maxn];
ll l, r, ans;
vector<ll> g[Maxn], w[Maxn];

struct Road
{
    ll from, to, val, lca;
    bool const operator<(Road b) const
    {
        return val > b.val;
    }
} road[Maxn];

void dfs(ll nowNode, ll fatherNode)
{
    // cout << nowNode << endl;
    deep[nowNode] = deep[fatherNode] + 1;
    father[nowNode][0] = fatherNode;
    for (ll i = 1; (1 << i) <= deep[nowNode]; i++)
        father[nowNode][i] = father[father[nowNode][i - 1]][i - 1];
    for (ll i = 0; i < g[nowNode].size(); i++)
    {
        ll nextNode = g[nowNode][i];
        if (nextNode == fatherNode)
            continue;
        dis[nextNode] = dis[nowNode] + w[nowNode][i];
        val[nextNode] = w[nowNode][i];
        dfs(nextNode, nowNode);
    }
}

ll lca(ll c1, ll c2)
{
    if (deep[c1] < deep[c2])
        swap(c1, c2);
    while (deep[c1] != deep[c2])
        c1 = father[c1][(ll)log2(deep[c1] - deep[c2])];
    while (c1 != c2)
    {
        ll nexti = 0;
        while (father[c1][nexti] != father[c2][nexti])
            nexti++;
        if (nexti != 0)
            nexti--;
        c1 = father[c1][nexti];
        c2 = father[c2][nexti];
    }
    return c1;
}

void dfsc(ll nowNode, ll fatherNode)
{
    for (ll i = 0; i < g[nowNode].size(); i++)
    {
        ll nextNode = g[nowNode][i];
        if (nextNode == fatherNode)
            continue;
        dfsc(nextNode, nowNode);
        sum[nowNode] += sum[nextNode];
    }
}

bool check(ll nowMid)
{
    ll cnt = 0, nowMaxn = 0;
    memset(sum, 0, sizeof(sum));
    for (ll i = 1; i <= m; i++)
    {
        if (road[i].val <= nowMid)
            break;
        sum[road[i].from]++;
        sum[road[i].to]++;
        sum[road[i].lca] -= 2;
        cnt++;
    }
    dfsc(1, 0);
    for (ll i = 1; i <= n; i++)
    {
        // cout << i << "    " << sum[i] << endl;
        if (sum[i] == cnt)
            nowMaxn = max(nowMaxn, val[i]);
    }
    return road[1].val - nowMaxn <= nowMid;
}

void init()
{
    cin >> n >> m;
    for (ll i = 1; i < n; i++)
    {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
        w[t1].push_back(t3);
        w[t2].push_back(t3);
        l = max(l, t3);
    }
    dfs(1, 0);
    for (ll i = 1; i <= m; i++)
    {
        ll t1, t2;
        cin >> t1 >> t2;
        road[i].from = t1;
        road[i].to = t2;
        road[i].lca = lca(t1, t2);
        road[i].val = dis[road[i].from] + dis[road[i].to] - dis[road[i].lca] * 2;
        r = max(r, road[i].val);
    }
    l = r - l;
    sort(road + 1, road + 1 + m);
}

void work()
{
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }else
            l = mid + 1;
    }
    cout << ans << endl;
}

int main()
{
    Buff;
    init();
    work();
    return 0;
}