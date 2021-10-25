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
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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

ll t, n;
String oriString1, oriString2;
ll ans;

void work()
{
    ans = 0;
    cin >> n;
    cin >> oriString1 >> oriString2;
    bool h0, h1;
    h0 = h1 = false;
    for (ll i = 0; i < n; i++)
    {
        if (oriString1[i] == '0' || oriString2[i] == '0')
            h0 = true;
        if (oriString1[i] == '1' || oriString2[i] == '1')
            h1 = true;
        if (h0 && h1)
        {
            ans += 2;
            h0 = h1 = false;
            continue;
        }
        if (h0)
        {
            if (i + 1 < n)
            {
                if (oriString1[i + 1] == '1' && oriString2[i + 1] == '1')
                {
                    i = i + 1;
                    ans += 2;
                    h0 = h1 = false;
                }
                else
                {
                    ans += 1;
                    h0 = h1 = false;
                }
            }
            else
            {
                ans += 1;
            }
        }
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