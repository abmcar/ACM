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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll n, c;
ll t1, t2;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> c;
    ll temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        t2 += 2;
        if (temp != 0)
            t1 += c;
    }
    while (__gcd(t1,t2) != 1)
    {
        temp = __gcd(t1,t2);
        t1 = t1 / temp;
        t2 = t2 / temp;
    }
    cout << t1 << "/" << t2 << endl;
    return 0;
}