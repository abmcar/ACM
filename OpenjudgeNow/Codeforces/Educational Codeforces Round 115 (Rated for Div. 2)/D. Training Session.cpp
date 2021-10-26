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

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t, n;
ll oriA[Maxn], oriB[Maxn];
map<ll, ll> numA, numB;
ll ans;

void work()
{
    ans = 0;
    numA.clear();
    numB.clear();
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> oriA[i] >> oriB[i];
        numA[oriA[i]]++;
        numB[oriB[i]]++;
    }
    ans = n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++)
        ans = ans - (numA[oriA[i]] - 1) * (numB[oriB[i]] - 1);
    // for (auto it : numB)
    // ans += it.second * ((totB-it.second)*totB - (totB2-it.second*it.second)*it.second - (totB-it.second)*it.second);
    cout << ans << endl;
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