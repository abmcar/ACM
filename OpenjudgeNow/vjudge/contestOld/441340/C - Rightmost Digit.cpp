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

ll quickPow(ll base, ll x)
{
    ll nowNum = 1;
    ll nowBase = base;
    while (x != 0)
    {
        if (x % 2 == 1)
        {
            x--;
            nowNum = nowNum * nowBase % 10;
        }
        nowBase = nowBase * nowBase % 10;
        x = x / 2;
    }
    return nowNum;
}

int t;
ll n;

int main()
{
    Buff;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << quickPow(n, n) << endl;
    }
    return 0;
}