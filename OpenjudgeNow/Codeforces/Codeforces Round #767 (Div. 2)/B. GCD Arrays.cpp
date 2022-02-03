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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;

void work()
{
    int l, r, k;
    cin >> l >> r >> k;
    int cnt = r - l + 1;
    int cnt1 = cnt / 2;
    if (cnt % 2 == 1)
        if (l % 2)
            cnt1++;
    // cout << cnt1 << endl;
    if (cnt1 <= k || (l != 1 && cnt == 1))
        cout << "YES" << endl;
    else
        cout << "No" << endl;
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