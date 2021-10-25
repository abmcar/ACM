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

const int Maxn = 1e6+10;
const ll Mod = 998244353;
ll n,m;
ll jc[Maxn];

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
    return now;
}


ll inverse(ll num)
{
    return quickPow(num,Mod-2);
}

int main()
{
    Buff;
    cin >> n >> m;
    jc[0] = 1;
    for(ll i = 1; i <= 1e6; i++)
        jc[i] = jc[i-1] * i % Mod;
    if(n == 1 || m == 1)
    {
        cout << "0" << endl;
        return 0;
    }
    // cout << jc[n+m-1] << " " << inverse(jc[n-2]) << " " << inverse(jc[m+1]) << " " << (m-1) << endl;
    cout << jc[n+m-1]%Mod*inverse(jc[n-2])%Mod*inverse(jc[m+1])%Mod*(m-1)%Mod << endl;
    return 0;
}
/*
n+m-2

C(n+m-1,n-2) = jc[n+m-1]*inverse(jc[n-2])*inverse(jc[m+1])*(m-1)

1
2
3
4
4

11 12 13 14
22 23 24
33 34
44
1 1 1 1
1 1 1
1 1
1
10

111 112 113 114 122 123 124 133 134 144
222 223 224 233 234 244 
333 334 344
444

10
6
3
1




1 4 10 20
fi = fi-1 *2 - fi-2 + 2
1 3 6 10 15 21
fi = fi-1 * 2 - fi-2 + 1
1 2 3 4 5
fi = fi-1 * 2 - fi-2

11111 11112 11113 11122 11123 111133 11222 11223 11233 11333 12222 12223 12233 12333 13333
*/