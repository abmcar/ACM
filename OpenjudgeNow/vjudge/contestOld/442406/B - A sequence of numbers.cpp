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

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 200907;

int n;
ll num1, num2, num3, k;

ll quick_Pow(ll base, ll x)
{
    ll nowNum = 1;
    ll nowBase = base;
    while (x)
    {
        if (x % 2 == 1)
        {
            nowNum = ((nowNum%Mod) * (nowBase%Mod)) % Mod;
            x--;
        }
        nowBase = ((nowBase%Mod) * (nowBase%Mod)) % Mod;
        x = x / 2;
    }
    return nowNum;
}

int main()
{
    // Buff;
    cin >> n;
    while (n--)
    {
        cin >> num1 >> num2 >> num3 >> k;
        if (num2 - num1 == num3 - num2)
        {
            ll d = num2-num1;
            cout << (num1 % Mod + (((k-1)%Mod) * (d%Mod))%Mod) % Mod << endl;
        }else
        {
            ll d = num2/num1;
            cout << num1*quick_Pow(d,k-1)%Mod << endl;
        }
    }
    return 0;
}