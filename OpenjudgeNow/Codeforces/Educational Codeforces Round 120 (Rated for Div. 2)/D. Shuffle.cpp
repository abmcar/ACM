#include "bits/stdc++.h"

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

const int Maxn = 1e4 + 10;
const ll Mod = 998244353;

String s;
int n, k, ans;
map<int, int> preAns;
map<int, int> M;
map<int, int> jc;

ll quickPow(ll base, ll x)
{
    ll now = 1;
    while (x)
    {
        if (x % 2)
            now = now * base % Mod;
        base = base * base % Mod;
        x = x / 2;
    }
    return now % Mod;
}

ll inverse(ll num)
{
    return quickPow(num, Mod - 2) % Mod;
    // if (num == 1)
    //     return num;
    // return inverse(Mod % num) * (Mod - Mod / num) % Mod;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    jc[0] = 1;
    for (int i = 1; i <= 5000; i++)
        jc[i] = jc[i - 1] * i % Mod;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        preAns[i] = preAns[i - 1] + s[i] - '0';
        M[preAns[i]] = i;
    }
    int maxLen = 0;
    for (int i = 0; i < n; i++)
        maxLen = max(maxLen, M[preAns[i - 1] + k] - i + 1);
    if (k >= maxLen)
    {
        cout << 1 << endl;
        return 0;
    }
    // cout << maxLen << endl;
    return 0;
}