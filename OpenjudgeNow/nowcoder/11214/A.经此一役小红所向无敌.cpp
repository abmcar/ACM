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
using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    ll a, b ,h ,k;
    cin >> a >> h >> b >> k;
    ll ans = 0;
    ll d1 = (h%b == 0) ? h/b : h/b+1;
    ll d2 = (k%a == 0) ? k/a : k/a+1;
    ans = min(d1, d2) * (a + b);
    // cout << d1 << " " << d2 << endl;
    if (d1 >  d2)
        ans = ans + 10 * a;
    if (d1 < d2)
        ans = ans + 10 * b;
    cout << ans << endl;
    return 0;
}