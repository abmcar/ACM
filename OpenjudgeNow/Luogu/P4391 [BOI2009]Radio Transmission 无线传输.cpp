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
// #define Debug

using namespace std;
using namespace __gnu_pbds;

const ll Maxn = 2e7 + 10;
const ll Mod = 1e9 + 7;

// string s, p;
char p[Maxn];
ll n, m;
ll nextPos[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    // cin >> n >> p >> m >> s;
    cin >> n >> p+1;
    // p = "-" + p;
    for (ll i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j+1]) j = nextPos[j];
        if (p[i] == p[j+1]) j++;
        nextPos[i] = j;
    }    
    ll ans = n-nextPos[n];
    // for (ll i = 1; i <= n; i++)
    // {
    //     if (nextPos[i] == 1 && nextPos[n])
    //     {
    //         bool ok = true;
    //         for (ll j = i; j <= n; j++)
    //             if (nextPos[j] != 1 + j-i)
    //             {
    //                 ok = false;
    //                 break;
    //             }
    //         if (ok)
    //         {
    //             cout << i - 1 << endl;
    //             return 0;
    //         }
    //     }
    // }
    cout << ans << endl;
    //     cout << nextPos[i] << " ";
    //     // ans = max(ans, nextPos[i]);
    // cout << ans << endl;
    // cout << endl;
    return 0;
}