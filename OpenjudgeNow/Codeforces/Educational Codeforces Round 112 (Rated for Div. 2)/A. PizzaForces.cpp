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
#include <bits/extc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t, n;

ll getVal(ll nowX)
{
    if (nowX < 0)
        return 1e15;
    if (nowX % 10 == 0 || nowX % 8 == 0 || nowX % 6 == 0)
        return nowX*5/2;
    ll ans = (nowX/8+1)*20;
    ans = min(ans, (nowX/10+1)*25);
    ans = min(ans, (nowX/6+1)*15);
    return ans;
}

void work()
{
    cin >> n;
    if (n % 10 == 0 || n % 8 == 0 || n % 6 == 0)
    {
        cout << n*5/2 << endl;
        return;
    }
    // if ((n-6) % 10 == 0 || (n-6) % 8 == 0)
    // {
    //     cout << (n-6)*2.5 + 15 << endl;
    //     return;
    // }
    // if ((n-8) % 10 == 0 || (n-8) % 6 == 0)
    // {
    //     cout << (n-8)*2.5 + 20 << endl;
    //     return;
    // }
    // if ((n-10) % 8 == 0 || (n-10) % 6 == 0)
    // {
    //     cout << (n-10)*2.5 + 25 << endl;
    //     return;
    // }
    // if ((n-16) % 8 == 0)
    // {
    //     cout << (n-16)*2.5 + 25 + 15 << endl;
    //     return;
    // }
    // if ((n-18) % 6 == 0)
    // {
    //     cout << (n-18)*2.5 + 25 + 20 << endl;
    //     return;
    // }
    // if ((n-14) % 10 == 0)
    // {
    //     cout << (n-14)*2.5 + 15 + 20 << endl;
    //     return;
    // }
    ll ans = getVal(n);
    if (n > 6)
    ans = min(ans , getVal(n-6) + 15);
    ans = min(ans , getVal(n-8) + 20);
    ans = min(ans , getVal(n-10) + 25);
    ans = min(ans , getVal(n-16) + 25 + 15);
    ans = min(ans , getVal(n-18) + 25 + 20);
    ans = min(ans , getVal(n-14) + 15 + 20);
    // cout << (n/8+1)*20 << " " << (n/10+1)*25 << " ";
    // cout << (n/6+1)*15 << endl;
    cout << ans << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while (t--)
        work();
    return 0;
}