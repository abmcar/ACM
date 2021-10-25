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

ll t, W, H, xx1, x2, yy1, yy2, w, h;

void work()
{
    cin >> W >> H;
    cin >> xx1 >> yy1 >> x2 >> yy2;
    cin >> w >> h;
    if (((x2 - xx1 + w) > W) && ((yy2 - yy1 + h) > H))
    {
        cout << -1 << endl;
        return;
    }
    // xx1++;
    // yy1++;
    ll minX = 1e9;
    ll minY = 1e9;
    // if (w >= xx1 && ((x2 - xx1 + w) <= W))
    //     minX = min(minX, w - xx1);
    // if ((W - w) <= x2 && ((x2 - xx1 + w) <= W))
    //     minX = min(minX, x2 - (W - w));
    // if (h >= yy1 && ((yy2 - yy1 + h) <= H))
    //     minY = min(minY, h - yy1);
    // if ((H - h) <= yy2 && ((yy2 - yy1 + h) <= H))
    //     minY = min(minY, yy2 - (H - h));
    if ((x2 - xx1 + w) <= W)
        minX = min(w - xx1, x2 - (W - w));
    if ((yy2 - yy1 + h) <= H)
        minY = min(h - yy1, yy2 - (H - h));
    ll ans = min(minX, minY);
    ans = max(0LL, ans);
    // if (minX == 0)
    if (ans == 1e9)
        ans = -1;
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