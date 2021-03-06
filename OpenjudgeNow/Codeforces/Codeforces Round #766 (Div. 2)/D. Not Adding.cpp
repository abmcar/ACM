#include <bits/stdc++.h>

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

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;
// int ok[Maxn+10];

void work()
{
    cin >> n;
    vector<bool> ok(Maxn + 1);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        ok[temp] = true;
    }
    int ans = 0;
    for (int i = 1; i <= Maxn; i++)
    {
        if (ok[i])
            continue;
        int cntNum = 0;
        for (int j = i * 2; j <= Maxn; j += i)
        {
            if (!ok[j])
                continue;
            cntNum = __gcd(cntNum,j);
        }
        if (cntNum == i)
            ans++;
    }
    cout << ans << endl;
}

signed main()
{
    // cout << __gcd(0,123);
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    // cin >> t;
    // while (t--)
        work();
    return 0;
}