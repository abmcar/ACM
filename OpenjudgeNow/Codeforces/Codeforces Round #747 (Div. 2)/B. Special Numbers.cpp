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
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t, n, k;

ll quick_pow(ll base, ll x)
{
    ll nowNum = 1;
    while (x)
    {
        if (x % 2)
            nowNum = nowNum * base % Mod;
        x = x / 2;
        base = base * base % Mod;
    }
    return nowNum;
}

void work()
{
    cin >> n >> k;
    ll nowBase = 0;
    ll ans = 0;
    while (k)
    {
        if (k % 2)
            ans = (ans + quick_pow(n, nowBase)) % Mod;
        nowBase++;
        k = k / 2;
    }
    cout << ans << endl;
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