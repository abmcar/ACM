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
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e5 + 10;
const ll Mod = 998244353;

int t, n;
ll f[Maxn], rF[Maxn];
string oriS;

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
}

void init()
{
    f[0] = rF[0] = 1;
    for (int i = 1; i <= 1e5; i++)
    {
        f[i] = f[i - 1] * i % Mod;
        rF[i] = inverse(f[i]) % Mod;
    }
}

void work()
{
    cin >> n;
    cin >> oriS;
    int t1, t2, t3;
    t1 = t2 = t3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (oriS[i] == '0')
            t2++;
        else if (i + 1 < n && oriS[i + 1] == '1')
            t1++, i++;
        else
            t3++;
    }
    // cout << t1 << " " << t2 << " " << t3 << endl;
    cout << ((f[t1 + t2] * (rF[t1] % Mod) % Mod) * (rF[t2] % Mod)) % Mod << endl;
}

int main()
{
    // cout << 2048*inverse(1024)%Mod << endl;
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    init();
    cin >> t;
    while (t--)
        work();
    return 0;
}