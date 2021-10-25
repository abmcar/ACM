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
ll nowMod;

ll quick_Pow(ll base, ll x)
{
    ll nowNum = 1;
    ll nowBase = base;
    while (x)
    {
        if (x % 2 == 1)
        {
            nowNum = nowNum * nowBase % nowMod;
            x--;
        }
        nowBase = nowBase * nowBase % nowMod;
        x = x / 2;
    }
    return nowNum;
}

ll n;
ll a,b,c;

int main()
{
    Buff;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        nowMod = c;
        cout << quick_Pow(a, b) << endl;
    }
    return 0;
}