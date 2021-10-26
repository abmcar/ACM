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
#include <ext/pb_ds/priority_queue.hpp>               
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

ll x, nowStars;
ll totDraw;
ll nowDraw;
ll ans;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> x;
    while (x >= 160 || nowStars >= 5)
    {
        ll nowDraw1 = x / 160;
        x = x - nowDraw1 * 160;
        ll nowDraw2 = nowStars / 5;
        nowStars = nowStars - 5 * nowDraw2;
        totDraw += nowDraw1 + nowDraw2;
        ans += nowDraw1 + nowDraw2;
        ll temp = totDraw / 10;
        nowStars += temp * 3;
        totDraw = totDraw % 10;
    }
    cout << ans << endl;
    return 0;
}                              