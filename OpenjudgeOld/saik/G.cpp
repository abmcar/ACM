#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
#define Maxn (int)2e6 + 7
using namespace std;

const ll Mod = 1e9+7;

int num[10];
ll tempp[Maxn];
ll tot, ans, temp;

ll quickPow(ll base, ll x)
{
    if (base == 0)
        return 0;
    ll now = 1;
    while (x != 0)
    {
        if (x % 2 == 0)
        {
            x = x / 2;
            base *= base;
            base = base % Mod;
            continue;
        }
        x--;
        now *= base;
        now = now % Mod;
    }
    return now;
}

inline ll inverse(ll num)
{
    return quickPow(num, Mod - 2);
}

inline ll cal(int n, int m)
{
    return ((tempp[n] * inverse(tempp[m]) % Mod) * (inverse(tempp[n - m]) % Mod)) % Mod;
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        cin >> num[i];
        tot += num[i];
    }
    tempp[0] = 1;
    for (int i = 1; i <= tot; i++)
        tempp[i] = tempp[i - 1] * i % Mod;
    ll res = 1, nw = tot;
    for (int i = 1; i <= 9; i++)
    {
        res = res * cal(nw, num[i]) % Mod;
        nw -= num[i];
    }
    for (int i = 1; i <= tot; i++)
        temp = (temp * 10 + 1) % Mod;
    for (int i = 1; i <= 9; i++)
        ans = (ans + num[i] * i) % Mod;
    cout << (((ans * temp % Mod) * res % Mod) % Mod * inverse(tot) % Mod) % Mod << endl;
    return 0;
}