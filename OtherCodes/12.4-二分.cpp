#include "bits/stdc++.h"

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

ll n, d;
ll num1[1234], num2[1234];
ll l, r, mid, ans;
ll minAns, maxAns;

ll cal(ll nowD)
{
    ll nowAns = 0;
    for (ll i = 1; i <= n; i++)
        nowAns = nowAns + (num1[i] - num2[i] + nowD) * (num1[i] - num2[i] + nowD);
    return nowAns;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> num1[i];
    for (ll i = 1; i <= n; i++)
        cin >> num2[i];
    cin >> d;
    sort(num1 + 1, num1 + 1 + n);
    sort(num2 + 1, num2 + 1 + n);
    for (ll i = 1; i <= n; i++)
        minAns += (num1[i] - num2[i]) * (num1[i] - num2[i]);
    sort(num2 + 1, num2 + 1 + n, greater<ll>());
    for (ll i = 1; i <= n; i++)
        maxAns += (num1[i] - num2[i]) * (num1[i] - num2[i]);
    sort(num2 + 1, num2 + 1 + n);
    cout << maxAns << " " << minAns << endl;
    l = d * -1;
    r = d;
    while (l <= r)
    {
        // cout << l << " " << r << endl;
        ll m1 = (l + r) / 2;
        ll m2 = (m1 + r) / 2;
        ans = min(ans, cal(m1));
        ans = min(ans, cal(m2));
        if (cal(m1) > cal(m2))
        {
            if (m1 == l)
                l = m1 + 1;
            else
                l = m1;
        }
        else
        {
            if (m2 == r)
                r = m2 - 1;
            else
                r = m2;
        }
    }
    cout << ans << endl;
    return 0;
}
/* 
3
3 2 1
4 5 6
4
 */