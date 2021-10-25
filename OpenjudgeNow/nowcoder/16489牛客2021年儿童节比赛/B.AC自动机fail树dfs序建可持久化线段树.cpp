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
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 998244353;

//48
int vp;
int p1, p2, p3;
ll finp;
int t;

ll quickPow(ll base, ll x)
{
    if (base == 0.0)
        return 0;
    // cout << base << " " << x << endl;
    ll now = 1;
    while (x != 0)
    {
        // cout << now << endl;
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

void work()
{
    cin >> vp;
    vp = 100 - vp;
    // p1 = vp*vp*2;
    // p2 = vp*vp;
    // p3 = p1+p2;
    // p3 = min(10000,p3);
    // cout << p1 << " " << p2 << endl;
    finp = vp*vp;
    // cout << finp << endl;
    ll inv = quickPow(10000,Mod-2);
    cout << finp * inv % Mod << endl;
}

int main()
{
    // Buff;
    cin >> t;
    // cout << quickPow(t,3) << endl;
    while (t--)
        work();
    return 0;
}