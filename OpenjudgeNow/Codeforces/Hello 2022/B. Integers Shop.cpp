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
#include <unordered_map>
#include <unordered_set>
// #include <ext/pb_ds/priority_queue.h>
// #include <bits/extc++.h>
// #include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t, n;
ll l[Maxn], r[Maxn], c[Maxn];
ll cntL, cntR, cntC;

void work()
{
    cin >> n;
    ll lCost, rCost;
    lCost = rCost = 1e12;
    ll cntLen = 0;
    ll lenCost = 1e12;
    cntL = 1e12;
    cntR = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i] >> c[i];
        // cout << cntL << " " << cntR << endl;
        // cout << l[i] << " " << r[i] << endl;
        if (cntL > l[i])
        {
            cntL = l[i];
            lCost = c[i];
        }
        if (cntR < r[i])
        {
            cntR = r[i];
            rCost = c[i];
        }
        if (cntL == l[i])
            lCost = min(lCost, c[i]);
        if (cntR == r[i])
            rCost = min(rCost, c[i]);
        cntC = lCost + rCost;
        if (r[i] - l[i] + 1 > cntLen)
            cntLen = r[i] - l[i] + 1,lenCost = c[i];
        if (cntLen == r[i] - l[i] + 1)
            lenCost = min(lenCost,c[i]);
        
        // cout << cntL << " " << cntR << " " << cntLen << endl;
        if (cntLen == cntR - cntL + 1)
            cntC = min(lenCost, cntC);

        cout << cntC << endl;
    }
}

signed main()
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