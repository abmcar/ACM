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
// #include <unordered_map>
// #include <unordered_set>
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
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
const ll Mod = 2e10;

int t;
ll n, s;
ll nums[Maxn];
ll nowNum;
ll nowL, nowR;
ll ans = 2e10;

void work()
{
    ans = 2e10;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    nowL = nowR = 1;
    nowNum = nums[1];

    while (nowL <= n)
    {
        while (nowNum < s)
        {
            if (nowR >= n)
            {
                nowR = n + 1;
                break;
            }
            nowR++;
            nowNum = nowNum + nums[nowR];
        }
        // cout << nowL << " " << nowR << " " << nowNum << " " << nowR-nowL+1 << endl;
        if (nowR <= n)
        {
            ans = min(ans, nowR - nowL + 1);
            nowNum = nowNum - nums[nowL];
        }
        nowL++;
    }
    if (ans == 2e10)
        ans = 0;
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