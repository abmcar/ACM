// #include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <iomanip>
// #include <cmath>
// #include <ctime>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <climits>
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <bits/extc++.h>
#include <bits/stdc++.h>
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

int t, n, k;
ll nowAns;

// ll quickMul(ll base, ll x)
// {
//     ll nowBase = 1;
//     while (x)
//     {
//         if (x % 2)
//             nowBase = nowBase * base % Mod;
//         x = x / 2;
//         base= base * base % Mod;
//     }
//     return nowBase;
// }

ll quickPow(ll base, ll x)
{
    ll nowBase = 1;
    while (x)
    {
        if (x % 2)
        {
            nowBase = nowBase * base % Mod;
            // nowBase = quickMul(nowBase,base);
            x = x - 1;
            continue;
        }
        base = base * base % Mod;
        // base = quickMul(base, base);
        x = x / 2;
    }
    return nowBase % Mod;
}

void work()
{
    cin >> n >> k;
    if (k == 0)
    {
        cout << 1 << endl;
        return;
    }
    // if (n % 2 == 1)
    // {
    //     cout << quickPow(quickPow(2,n-1)+1,k) << endl;
    //     return;
    // }
    ll nowBaseNum = quickPow(2, n - 1);
    ll unableNum = quickPow(2, n - 1);
    if (n % 2 == 1)
        nowBaseNum++, unableNum--;
    // cout << nowBaseNum << " " << unableNum << endl;
    // nowBaseNum--;
    // nowBaseNum++;
    // cout << nowBaseNum << endl;
    nowAns = 0;
    ll tempNum = 0;
    for (int i = 1; i <= k; i++)
    {
        tempNum = quickPow(unableNum, k - i) % Mod;
        ll tempNum2 = quickPow(quickPow(2, n), i - 1) % Mod;
        // tempNum = tempNum * nowBaseNum * % Mod;
        // if (quickPow(unableNum-1, k - i) < 0)
        // {
        //     cout << i << " " << quickPow(unableNum-1, k - i) << endl;
        //     cout << unableNum << " "  << k - 1 << endl;
        //     return;
        // }
        tempNum = (tempNum % Mod * tempNum2 % Mod * nowBaseNum) % Mod;
        nowAns = (nowAns + tempNum) % Mod;
    }
    // if (n % 2 == 0)
    //     nowAns = (nowAns + quickPow(unableNum-1,k)) % Mod;
    // else
    //     nowAns = quickPow(nowBaseNum,k) % Mod;
    cout << nowAns << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    // cout << quickPow(2,60522) << endl;
    cin >> t;
    while (t--)
        work();
    return 0;
}