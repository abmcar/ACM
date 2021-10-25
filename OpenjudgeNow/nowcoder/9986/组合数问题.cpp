#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
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
const ll Mod = 998244353;

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
    for(int i = 1; i <= n; i++)
        n1 = n1 * i % Mod;
    for(int i = 1; i <= r; i++)
        n2 = n2 * i % Mod;
    for(int i = 1; i <= n-r; i++)
        n3 = n3 * i % Mod;
    ans = (n1 * inverse(n2) % Mod * inverse(n3) % Mod) % Mod;
    // cout << n << " " << r << endl;
    return ans;
}

unsigned long long n;

int main()
{
    Buff;
    cin >> n;
    ll ans;
    ll k = n/4;
    if(k % 2 == 1)
        ans = (quickPow(16,k)*inverse(4))%Mod - (quickPow(4,k) * inverse(2))%Mod;
    else
        ans = (quickPow(16,k)*inverse(4))%Mod + (quickPow(4,k) * inverse(2))%Mod;
    if(ans <= 0)
        ans += Mod;
    cout << ans%Mod;
    // n = n/4;
    // ll n1 = quickPow(-4,n)*inverse(2);
    // ll n2 = quickPow(16,n)*inverse(4);
    // if(n1 <= 0)
    //     n1 += Mod;
    // if(n2 <= 0)
    //     n2 += Mod;
    // cout << (n1+n2)%Mod;
    // cout << ((quickPow(-4,n)*2+quickPow(16,n))/4)%Mod << endl;
        
    // for(int i = 4; i <= n; i+=4)
    // {
    //     int ans = 0;
    //     for(int j = 0; j <= i; j+=4)
    //         ans += getC(j,i),cout << getC(j,i) << " ";
    //     cout << endl;
    //     cout << i << " " << ans << endl;
    // }
    return 0;
}
/*

n!       +      n!
0!*n!           4!*(n-4)!

n^(n/4)*invsrse(r)*invsrse(r+4)*invsrse(r)

*/