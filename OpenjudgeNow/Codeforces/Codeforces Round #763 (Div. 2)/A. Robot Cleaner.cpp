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

int t, n, m;
int rb, cb, rd, cd;

void work()
{
    cin >> n >> m;
    cin >> rb >> cb >> rd >> cd;
    int ans = 1e9;
    if (rb > rd)
        ans = 2 * n - rb - rd;
    else
        ans = rd - rb;
    if (cb > cd)
        ans = min(ans, 2 * m - cb - cd);
    else
        ans = min(ans, cd - cb);
    cout << ans << endl;
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