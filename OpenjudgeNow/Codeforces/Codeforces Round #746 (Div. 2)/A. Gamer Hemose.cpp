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
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t, n, p;
ll max1, max2;

void work()
{
    max1 = max2 = 0;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        if (temp > max1)
        {
            max2 = max1;
            max1 = temp;
            continue;
        }
        if (temp > max2)
        {
            max2 = temp;
            continue;
        }
    }
    // cout << max1 << " " <<  max2 << endl;
    ll ans = (p / (max1 + max2));
    p = p - ans * (max1 + max2);
    ans = ans * 2;
    // cout << p << endl;
    if (p)
    {
        ans++;
        if (p > max1)
            ans++;
    }
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