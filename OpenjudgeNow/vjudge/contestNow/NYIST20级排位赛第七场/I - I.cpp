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

ll n, d;
vector<int> V;
ll ans;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        V.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int nextPos = upper_bound(V.begin(),V.end(),V[i]+d) - V.begin();
        nextPos--;
        if (nextPos - i <= 1)
            continue;
        ll t= nextPos-i;
        ans += t*(t-1)/2;
        // cout << V[i] << " " << V[i]+d << " " << V[nextPos] << endl;
    }
    cout << ans << endl;
}