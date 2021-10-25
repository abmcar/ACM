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

const ll Maxn = 2e5 + 10;
const ll Mod = 1e9 + 7;

ll t, n, m;
long long num[Maxn];
ll preans[8][Maxn];

void work()
{
    cin >> n >> m;
    string oriS;
    cin >> oriS;
    unordered_map<int,int> M[8];
    map<int,string> MP;
    MP[1] = "abc";
    MP[2] = "acb";
    MP[3] = "bac";
    MP[4] = "bca";
    MP[5] = "cab";
    MP[6] = "cba";
    for (ll i = 0; i < oriS.size(); i++)
    {
        for (int j = 1; j <= 6; j++)
            if (oriS[i] != MP[j][i%3])
                M[j][i+1] = 1;
        // if (i % 3 == 0)
        // {
        //     if (oriS[i] == 'a')
        //         M[1][i]++, M[2][i]++;
        //     if (oriS[i] == 'b')
        //         M[3][i]++, M[4][i]++;
        //     if (oriS[i] == 'c')
        //         M[5][i]++, M[6][i]++;
        // }
        // if (i % 3 == 1)
        // {
        //     if (oriS[i] == 'a')
        //         M[3][i]++, M[5][i]++;
        //     if (oriS[i] == 'b')
        //         M[1][i]++, M[6][i]++;
        //     if (oriS[i] == 'c')
        //         M[2][i]++, M[4][i]++;
        // }
        // if (i % 3 == 2)
        // {
        //     if (oriS[i] == 'a')
        //         M[4][i]++, M[6][i]++;
        //     if (oriS[i] == 'b')
        //         M[2][i]++, M[5][i]++;
        //     if (oriS[i] == 'c')
        //         M[1][i]++, M[3][i]++;
        // }
    }
    ll pos, maxn;
    maxn = 0;
    for (ll i = 1; i <= 6; i++)
    {
        for (ll j = 0; j <= n; j++)
            preans[i][j] = preans[i][j-1] + M[i][j];
    }
    for (ll i = 1; i <= m ;i++)
    {
        ll t1, t2;
        cin >> t1 >> t2;
        // if (t2 - t1 == 0)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }
        // if (t2 - t1 == 1)
        // {
        //     if (oriS[t1-1] == oriS[t2-1])
        //         cout << 1 << endl;
        //     else
        //         cout << 0 << endl;
        //     continue;
        // }
        ll ans = 1e9;
        if (t1 - 1 < 0)
        {
            for (ll j = 1; j <= 6; j++)
                ans = min(ans, preans[j][t2]);
        }else
        for (ll j = 1; j <= 6; j++)
            ans = min(ans, (preans[j][t2]-preans[j][t1-1]));
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
    // cin >> t;
    // while (t--)
        work();
    return 0;
}