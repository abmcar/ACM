#include <stdio.h>

#define ll long long
const ll Mod = 1e9 + 7;

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

ll n;

ll ans = 0;
ll nowNum = 2;
int flag3 = 0;
int flag = 0;
int main()
{
    // cin >> n;
    scanf("%lld", &n);
    // printf("%lld",n);
    while (n--)
    {
        ll temp;
        scanf("%lld", &temp);
        ans = ans | (temp % 2 == 0);
        nowNum = quick_pow(nowNum, temp) % Mod;
    }
    if (nowNum % 2 == 0)
        nowNum = nowNum / 2;
    else
        nowNum = (nowNum + Mod) / 2;
    ans = !ans;
    ll num1 = nowNum;
    ll num2 = nowNum;
    if (ans)
        num1--;
    else
        num1++;
    if (flag3 == 0 && num1 % 3 == 0)
    {
        num1 = num1 / 3;
        flag3 = 1;
    }
    if (flag3 == 0 && (num1+Mod) % 3 == 0)
    {
        num1 = (num1+Mod) / 3;
        flag3 = 1;
    }
    if (flag3 == 0)
        num2 = num2 * 3;
    printf("%lld %lld",num1,num2);
    return 0;
}