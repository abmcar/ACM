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
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const ll Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

ll t, n, k;
ll a[Maxn];

void work()
{
    cin >> n >> k;
    ll ans = -1e15;
    ll maxn = 0;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], maxn = max(maxn, a[i]);
    ll minAns = k * maxn * 2;
    ll strPos = max(1LL, n - (ll)sqrt(minAns) - 1);
    for (ll i = strPos; i < n; i++)
    for (ll j = i + 1; j <= n; j++)
        ans = max(ans, i * j - k * (a[i]|a[j]));
    cout << ans << endl;
    // cout << strPos << endl;
}
int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}