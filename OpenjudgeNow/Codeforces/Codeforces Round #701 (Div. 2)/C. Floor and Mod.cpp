#include <iostream>
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

using namespace std;

const int Maxn = 1e7+10;
const ll Mod = 1e9+7;
int t;
ll x,y;

void work()
{
    ll ans = 0;
    cin >> x >> y;

    ll nex = 1;
    // while (nex <= y+1)
    // {
    //     ll res = y+1 / nex;
    //     ll bound = y+1 / res;  
    //     ans += res * (bound - nex + 1);
    //     nex = bound + 1;
    // }
    
    // for(ll b = 2; b <= sqrt(x+1); b++)
    //     ans += b-1-x/(b+1);

    for(ll b = 2; b <= min(x,y); b++)
        ans += min(b-1,x/(b+1));
// 2 3 4
// 1 2 3
// 1 0 0
// for(int L=1,R;L<=y;L=R+1)
// {
//     R=x/(x/L);
//     ans+=(R-L+1)*(x/L);
// }

    cout << ans << endl;
}

int main()
{
    Buff;
    cin >> t;
    while(t--)
        work();
    return 0;
}

/*
9 9
0 1 2 1 1 1 1 1 0
16 16
0 1 2 3 2 2 2 1 1 1 1 1 1 1 1 0

b-1 < x/(b+1)

b < sqrt(x+1)
b-1
b > sqrt(x+1)
x/sqrt(x+1) x/sqrt(x+1)+1 x/sqrt(x+1)+2


a / b = k -- m;

k * b + k = a;
k*(b+1) = a (b > k)
a/b = a % b
*/