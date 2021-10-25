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

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

ll n, l, r, ans;
ll maxn;
ll h[Maxn];

bool check(ll nowE)
{
    for (int i = 1; i <= n; i ++)
    {
        if (h[i] > nowE)
            nowE = nowE - (h[i] - nowE);
        else
            nowE = nowE + (nowE - h[i]);
        // cout << i << " " << nowE << endl;
        if (nowE < 0)
            return false;
        if (nowE >= maxn * 1000)
            nowE = maxn * 1000;
    }
    return true;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i], maxn = max(maxn, h[i]);
    l = 0;
    r = maxn;
    while (l <= r)
    {
        // cout << l << " " << r << endl;
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}