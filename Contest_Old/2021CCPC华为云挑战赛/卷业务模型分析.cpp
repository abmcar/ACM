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
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t;
ll m;
ll a1[Maxn], a2[Maxn];
ll b[Maxn];
ll minn1, minn2;
ll minpos1, minpos2;

void work()
{
    cin >> m;
    ll tot1, tot2, tot3;
    tot1 = tot2 = tot3 = 0;
    minn1 = minn2 = 1e9;
    for (ll i = 1; i <= m; i++)
    {
        cin >> a1[i];
        if (a1[i] < minn1)
        {
            minn1 = a1[i];
            minpos1 = i;
        }
    }
    for (ll i = 1; i <= m; i++)
    {
        cin >> a2[i];
        if (a2[i] < minn2)
        {
            minn2 = a2[i];
            minpos2 = i;
        }
    }
    for (ll i = 1; i <= m; i++)
        cin >> b[i];
    for (ll i = 1; i <= m; i++)
    {
        tot1 += a1[i];
        tot2 += a2[i];
        tot3 += b[i];
    }
    // ll avg1 = tot1 / (ll)m;
    // ll avg2 = tot2 / (ll)m;
    // ll avg3 = tot3 / (ll)m;
    // // ll b1 = b[minpos1] - a1[minpos1];
    // // ll b2 = b[minpos2] - a2[minpos2];
    ll b1 = (tot3-tot1) / m;
    ll b2 = (tot3-tot2) / m;
    long double k1 = (tot3 - b1 * m) / (long double)tot1;
    long double k2 = (tot3 - b2 * m) / (long double)tot2;
    ll cnt1 , cnt2;
    cnt1 = cnt2 = 0;
    // cout << b1 << " " << b2 << " " << k1 << " " << k2 << endl;
    for (ll i = 1; i <= m; i++)
    {
        cnt1 = max((long double)cnt1,b[i] - k1 * a1[i] - b1);
        cnt2 = max((long double)cnt2,b[i] - k2 * a2[i] - b2);
    }
    // cout << cnt1 << " " << cnt2 << endl;
    if (cnt1 < cnt2)
        cout << 1 << endl;
    else
        cout << 2 << endl;
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