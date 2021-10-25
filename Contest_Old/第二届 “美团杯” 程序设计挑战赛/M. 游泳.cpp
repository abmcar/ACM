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

const ll Maxn = 200 + 10;
const ll Mod = 1e9 + 7;

ll t;
ll n, k ,m;
ll num[Maxn];

void work()
{
    cin >> n >> m >> k;
    if (m > n)
    {
        cout << -1 << endl;
        return;
    }
    if (k == 0 && n % m != 0)
    {
        cout << -1 << endl;
        return;
    }
    ll orin = n;
    ll a = max((ll)1,n/m - (m-1)*k/2); 
    ll now = 0;
    memset(num,0,sizeof(num));
    num[1] = now = a;
    for (ll i = 2; i <= m; i++)
        num[i] = min(num[i-1] + k,n-now), now += num[i];
    n = n - now;
    for (ll i = 1; i <= m; i++)
        num[i] += (n/m);
    for (ll i = 1; i <= n % m; i++)
        num[i]++;
    ll temp = 0;
    for (int i = 1; i <= m; i++)
        temp += num[i];
    if (temp != orin)
    {
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    for (ll i = 1; i <= m; i++)
        ans += (num[i]*num[i]*m*m - 2*num[i]*orin*m + orin*orin);
    cout << ans/m << endl;
}

int main()
{
    // Buff;
    cin >> t;
    while (t--)
        work();
    return 0;
}