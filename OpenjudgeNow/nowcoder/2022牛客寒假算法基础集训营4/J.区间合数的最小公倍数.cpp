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

const int Maxn = 30010;
const ll Mod = 1e9 + 7;

int l, r;
ll ans = 1;
vector<int> primes;
vector<int> ok(Maxn * 2), used(Maxn * 2);
unordered_map<int, int> M;

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

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    for (int i = 2; i <= Maxn; i++)
    {
        if (used[i])
            continue;
        ok[i] = true;
        primes.push_back(i);
        for (int j = 2; j * i <= Maxn; j++)
            used[j * i] = true;
    }
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (ok[i])
            continue;
        int nowNum = i;
        for (int j = 0; j < primes.size(); j++)
        {
            if (nowNum < primes[j])
                break;
            int cnt = 0;
            while (nowNum % primes[j] == 0)
            {
                cnt++;
                nowNum = nowNum / primes[j];
            }
            M[primes[j]] = max(M[primes[j]], cnt);
            if (nowNum == 1)
                break;
        }
    }
    if (M.size() == 0)
        ans = -1;
    for (auto it : M)
    {
        // for (int j = 1; j <= it.second; j++)
        ans = ans * quick_pow(it.first, it.second) % Mod;
    }
    cout << ans << endl;
    return 0;
}