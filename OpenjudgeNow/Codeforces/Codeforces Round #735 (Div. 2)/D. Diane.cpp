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

int t, n;

void work()
{
    cin >> n;
    // int len = 0;
    // // while (len < n)
    // // {
    // //     len++;
    // //     if (n % len != 0)
    // //         continue;
    // //     if (n % (2*len) != 0)
    // //         continue;
    // //     // if (n/(2*len) % 2 == 0)
    // //     //     continue;
    // //     cout << len << endl;
    // //     break;
    // // }
    if (n == 1)
    {
        cout << "a" << endl;
        return;
    }    
    if (n == 2)
    {
        cout << "ab" << endl;
        return;
    }
    string ans = string(n/2,'a');
    if (n % 2 == 0)
        ans = ans + 'b';
    else
        ans = ans + "bc";
    ans = ans + string(n/2-1,'a');
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