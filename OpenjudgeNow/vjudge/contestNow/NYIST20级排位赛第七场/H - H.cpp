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

signed main()
{
    Buff;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll temp1 = sqrt(n);
        ll temp2 = sqrt(n) + 1;
        ll cost1 = temp1 - 1;
        ll cost2 = temp2 - 1;
        cost1 += n/temp1;
        cost2 += n/temp2;
        if (n % temp1 == 0)
            cost1--;
        if (n % temp2 == 0)
            cost2--;
        cout << min(cost1,cost2) << endl;
            // cout << min((int)(sqrt(n))-1+n/((int)(sqrt(n)))) << endl;
        // cout << n/(int)sqrt(n) 
    }
    // cout << ((int)sqrt(5))*2 << endl;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
}
/*
1 0
2 1
3 2
4 2
5 3
6 3
7 4
8
*/