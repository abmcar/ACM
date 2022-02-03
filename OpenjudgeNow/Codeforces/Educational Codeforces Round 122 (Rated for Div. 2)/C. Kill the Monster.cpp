#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug
#define int long long

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;
int hc, dc, hm, dm;
int k, w, a;

void work()
{
    cin >> hc >> dc >> hm >> dm;
    cin >> k >> w >> a;
    for (int i = 0; i <= k; i++)
    {
        int nowHealth = hc + a * i;
        int nowDamage = dc + w * (k - i);
        if (((nowHealth + dm - 1LL) / dm >= (hm + nowDamage - 1LL) / nowDamage) || (nowDamage >= hm))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << Endl;
}

signed main()
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