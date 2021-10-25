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
#define Inf ll_MAX
#define endl "\n"

using namespace std;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll num[7] = {1,1,4,5,1,4};
map<ll,ll> M;


void dfs(ll now, ll deep)
{
    if (std::abs(now) >= 200 || deep >= 20)
        return;
    if (M[now] == 0)
        M[now] = deep;
    else
    {
        M[now] = min(M[now], deep);
    }
    dfs(now+num[deep%6],deep+1);
    dfs(now-num[deep%6],deep+1);
}

int main()
{
    Buff;
    dfs(1,1);
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n < 0)
        {
            cout << M[(n+15)%16-15]-6*((n+15)/16) << endl;
            // if (M[(n+15)%16-15]-6*((n+15)/16) != M[n])
            //     cout << "unppp" << endl;
        }
        else    
        {
            ll ans = M[n % 16];
            ans += 6*(n/16);
            // cout << M[(n+15)%16-15]-6*((n+15)/16) << " ";
            if (n % 16 == 0 && n >=16)
                ans -= 2;
            if ((n % 16 == 5 || n % 16 == 7)&& n >=16)
                ans -= 3;
            cout << ans << endl;
        }
    }
    // for (ll i = -50; i < 100; i++)
    // if (M[i] - 6*(i/16) !=  M[i%16] &&  (M[i] + 6*((i+15)/16) !=  M[(i+15)%16-15]))
    // if (M[i] == 0)
    //     continue;
    // else
    //     // cout << i << " " << i % 16 << " " << M[i] << " " << M[(i+15)%16-15] -6*((i+15)/16) << endl;
    //     cout << i << " " << M[i] << " " << M[i%16] + 6*(i/16) << "    " << M[i] - 6*(i/16 + 1) << endl;
    return 0;
}