#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll father[Maxn];
ll n, m, r;
ll ans;

ll find(ll son)
{
    if (father[son] == son)
        return son;
    father[son] = find(father[son]);
    return father[son];
}

struct Edge
{
    ll from, to, val;
    bool operator<(Edge b) const
    {
        return val > b.val;
    }
} edge[Maxn];

int t;

signed main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    // cin >> t;
    scanf("%lld",&t);
    while (t--)
    {
        ans = 0;
        // cin >> n >> m >> r;
        scanf("%lld %lld %lld", &n, &m, &r);
        for (ll i = 0; i <= n + m; i++)
            father[i] = i;
        for (ll i = 1; i <= r; i++)
        {
            scanf("%lld %lld %lld", &edge[i].from, &edge[i].to, &edge[i].val);
            // cin >> edge[i].from >> edge[i].to >> edge[i].val;
            edge[i].to += n;
        }
        sort(edge + 1, edge + 1 + r);
        for (ll i = 1; i <= r; i++)
        {
            ll f1 = find(edge[i].from);
            ll f2 = find(edge[i].to);
            if (f1 == f2)
                continue;
            father[f1] = f2;
            ans += edge[i].val;
        }
        // cout << ans << endl;
        printf("%lld\n",(n + m) * 10000 - ans);
        // cout << (n + m) * 10000 - ans << endl;
    }
    return 0;
}