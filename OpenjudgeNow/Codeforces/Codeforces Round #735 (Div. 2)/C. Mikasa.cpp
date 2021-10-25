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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;

void work()
{
    // unordered_map<int,bool> M;
    // // for (int i = 1; i <= 2 * n *m ; i++)
    // //     M[i] = false;
    // for (int i = 0; i <= m; i ++)
    //     M[n xor i] = true;
    // int nowPos = 0;
    // while (M[nowPos] == true)
    //     nowPos++;
    // return nowPos;
    cin >> n >> m;
    if (n > m)
    {
        cout << 0 << Endl;
        return;
    }
    ++m;
    int ans = 0;
    for (int k = 31; k >= 0 && n < m; k--)
    {
        // cout << (n >> k)% 2 << endl;
        if ((n >> k & 1) == (m >> k & 1))
            continue;
        if (m >> k & 1)
            ans |= 1 << k, n |= 1 << k;
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
    // for (int i = 0; i <= 16; i++)
    //     for (int j = 0; j <= t; j++)
    //     {
    //         n = i;
    //         m = j;
    //         if (i > j && work() == 0)
    //             continue;
    //         cout << i << " " << j << " " << j - i << " " << (j xor (j - i)) << " " << work() << endl;
    //         // work();
    //     }
    while (t--)
        work();
    return 0;
}