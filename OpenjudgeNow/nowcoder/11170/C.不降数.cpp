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
const ll Mod = 100019;

ll t;

ll quickPow(ll x, ll p)
{
    ll ans = 1;
    while(p)
    {
        if(p&1)
            ans = (ans*x)%Mod;
        x = (x*x) % Mod;
        p = p /2;
    }
    return ans;
}

ll inverse(ll num)
{
    return quickPow(num,Mod-2);
}

ll getC(ll r,ll n)
{
    ll n1,n2,n3,ans;
    n1 = n2 = n3 = 1;
    for(ll i = 1; i <= n; i++)
    {
        n1 = n1 * i;
        if (n1 % Mod != 0)
            n1 = n1 % Mod;
    }
    for(ll i = 1; i <= r; i++)
    {
        n2 = n2 * i;
        if (n2 % Mod != 0)
            n2 = n2 % Mod;
    }
    for(ll i = 1; i <= n-r; i++)
        n3 = n3 * i % Mod;
    ans = (n1 * inverse(n2) % Mod * inverse(n3) % Mod) % Mod;
    // cout << n << " " << r << endl;
    // cout << n1 << " " << n2 << ' ' << n3 << endl;
    return ans;
}


int main()
{
    Buff;
    cin >> t;
    // for (int i = 1234567; i <= t; i++)
    cout << getC(t,8+t) << endl;
    return 0;
}
/*
9  8  7  6  5  4  3 2 1
45 36 28 21 15 10 6 3 1
*/