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
const ll Mod = 1e9 + 7;

ll n ,m;

ll muti(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    ll nowNum = 0;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            nowNum = (nowNum + a) % m;
            b--;
        }
        a = (a + a) % m;
        b = b / 2;
    }
    return nowNum;
}

ll quickPow(ll base, ll x)
{
    ll nowNum = 1;
    ll nowBase = base;
    while (x != 0)
    {
        if (x % 2 == 1)
        {
            x--;
            nowNum = muti(nowNum,nowBase) % m;
        }
        nowBase = muti(nowBase,nowBase) % m;
        x = x / 2;
    }
    return nowNum;
}

int main()
{
    Buff;
    while (cin >> n >> m)
    {
        if (n + m == 0)
            break;
        if (n == 1)
            cout << 1 % m << endl;
        else
            cout << (quickPow(2, n) - 2 + m) % m<< endl;
    }
    return 0;
}