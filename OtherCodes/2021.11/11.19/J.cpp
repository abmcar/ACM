#include <stdio.h>

#define ll long long
const int Mod = 1e6 + 7;

int n, m;

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

int main()
{
    while (scanf("%d %d", &n, &m) != EOF)
        printf("%d\n", quick_pow(n, m) % Mod);
    return 0;
}
