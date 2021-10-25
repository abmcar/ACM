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

const ll Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

ll n, m;
ll atk, def;
ll totS, maxS, minS;
ll S[Maxn];

void work()
{
    totS = maxS = 0;
    minS = 1e20;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        totS += temp;
        maxS = max(maxS, temp);
        minS = min(minS, temp);
        S[i] = temp;
    }
    ll oriS = totS;
    sort(S + 1, S + 1 + n);
    cin >> m;
    for (ll i = 1; i <= m; i++)
    {
        cin >> def >> atk;
        ll t1 = *lower_bound(S + 1, S + 1 + n, def);
        ll t2 = *(lower_bound(S + 1, S + 1 + n, def)-1);
        ll ans = 1e20;
        if (t1 == 0)
            ans = min(ans, def-maxS+max((ll)0, atk - (totS - maxS)));
        else
            ans = min(ans, max((ll)0, atk - (totS - t1)));
            
        if (t2 == 0)
            ans = min(ans, max((ll)0, atk - (totS - minS)));
        else
            ans = min(ans, def-t2+max((ll)0, atk - (totS - t2)));
        cout << ans << endl;
    }
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    work();
    return 0;
}