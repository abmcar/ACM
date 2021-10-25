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
#define Buff std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;

ll quickPow(ll x, ll p)
{
    ll now = 1;
    ll base = x;
    while(p != 0)
    {
        if(p % 2 == 1)
        {
            now = now * base % Mod;
            p--;
            continue;
        }
        base = base * base % Mod;
        p = p / 2;
    }
    // cout << x << endl;
    return now % Mod;
}

int main()
{
    Buff;
    ll n;
    cin >> n;
    cout << n % Mod << endl;
    cout << (2*n-1) % Mod << endl;
    cout << (n%Mod)*(n%Mod)%Mod << endl;
    cout << quickPow(2,n-1) << endl;
    cout << quickPow(2,quickPow(2,n-1)) << endl;
    cout << ((n%2==1)?1:2) << endl;

    ll temp = 1;
    ll base = 10;
    ll t1 = 1;
    n--;
    while(n != 0)
    {
        for(int i = 1; i <= n%10; i++)
        {
            temp = temp * base + t1;
            temp = temp % Mod;
        }
        n = n / 10;
        base = base * 10;
        t1 = t1 * 10 + 1;
        base = base % Mod;
        t1 = t1 % Mod;
    }
    cout << temp << endl;
    return 0;
}