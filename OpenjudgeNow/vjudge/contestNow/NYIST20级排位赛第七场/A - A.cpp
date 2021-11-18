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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int f[Maxn][Maxn];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    //     ll n , m;
    //     cin >> n >> m;
    //     ll oriNum = 1;
    //     for (int i = 1; i <= m; i++)
    //         oriNum = oriNum * n % Mod;
    //     cout << oriNum << endl;
    // }
    f[1][1] = 1;
    for (int i = 2; i <= 20; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = f[i-1][j] + f[i-1][j-1];
            cout << f[i-1][j] + f[i-1][j-1] << " ";
        }

        cout << endl;
    }
    // int maxn = 0;
    // int n = 10;
    // int cnt = 0;
    // for (int a1 = 1; a1 <= 15; a1++)
    // for (int a2 = 1; a2 <= 15; a2++)
    // for (int a3 = 1; a3 <= 15; a3++)
    // for (int a4 = 1; a4 <= 15; a4++)
    // // for (int a5 = 1; a5 <= 31; a5++)
    // {
    //     set<int> S;
    //     S.insert(a1);
    //     S.insert(a2);
    //     S.insert(a3);
    //     S.insert(a4);
    //     // S.insert(a5);
    //     if (S.size() != 4)
    //         continue;
    //     // if (a1 + a2+a3 +a4 != 45)
    //     //     continue;
    //     // cout << (a1&a2&a3) << endl;
    //     if ((a1&a2&a3&a4) == 0)
    //     {
    //         cnt++;
    //         maxn = max(maxn,a1+a2+a3+a4);
    //         // cout << a1 << " " << a2 << " " << a3 << " " << a4  << " " << a1+a2+a3+a4+a5 << endl;
    //     }
    // }
    // cout << maxn << endl;
    // cout << cnt << endl;
    // ll nowNum = 100000;
    // for (int i = 1; i <= 20; i++)
    // {
    //     // static ll nowNum = 100000;
    //     nowNum = (nowNum * 100000) % Mod;
    //     cout << i << " " << nowNum << endl;
    // }
}
/*
3 1 0
3 2 6    6
3 3 24   6
3 4 78   6
3 5 240  6
3 6 726  6
3 7 2184 6
3 8 6558 6

4 2 0
4 3 24
4 4 168 24 + 24 * 6
4 5 840 168+24*28
4 6

2 2 4
2 3 6
3 3 24
3 3 78
3 4 240
4 3 24
4 4 168
4 5 840
5 3 0
5 4 120
5 5 1320
*/