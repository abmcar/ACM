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

int t, n;
string s1, s2;

void work()
{
    cin >> n;
    cin >> s1 >> s2;
    ll cnt[3][3] = {};
    for (int i = 0; i < n; i++)
        cnt[s1[i] - '0'][s2[i] - '0']++;
    ll ans = Mod;
    if (cnt[1][1] == cnt[0][0] + 1)
        ans = min(ans, cnt[0][0] * 2 + 1);
    if (cnt[1][0] == cnt[0][1])
        ans = min(ans, cnt[0][1] * 2);
    if (ans == Mod)
        ans = -1;
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