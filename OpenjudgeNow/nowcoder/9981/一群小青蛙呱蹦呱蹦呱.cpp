#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#define Maxn (int)2e8 + 10
#define Mod (int)(1e9 + 7)
#define ll long long

using namespace std;

ll n;
bool vised[Maxn];
int primes[Maxn];
int nowPrimeNum;
ll g = 1;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    if (n < 6)
    {
        cout << "empty";
        return 0;
    }
    for (ll i = 2; i <= n; i++)
    {
        if (vised[i] == 0)
        {
            vised[i] = 1;
            primes[++nowPrimeNum] = i;
        }
        for (ll j = 1; primes[j] * i <= n; j++)
        {
            vised[i * primes[j]] = 1;
            if (i % primes[j] == 0)
                break;
        }
    }
    for (int i = 2; primes[i] <= n / 2; i++)
    {
        int base = primes[i];
        ll nowNum = 1;
        while (nowNum * base <= n / 2)
            nowNum = nowNum * base % Mod;
        g = g * nowNum % Mod;
    }
    ll nowNum = 1;
    while (nowNum * 2 <= n / 3)
        nowNum = nowNum * 2 % Mod;
    g = g * nowNum % Mod;
    cout << g;
    return 0;
}
