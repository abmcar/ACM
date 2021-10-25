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

int t, n;
ll arr[Maxn];
long double preAns[Maxn];
long double ans;

void work()
{
    ans = -2e9;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    // sort(arr + 1, arr + 1 + n);
    int pos = 0;
    for (int i = 1; i <= n; i++)
        if (arr[i] > ans)
        {
            ans = arr[i];
            pos = i;
        }
    swap(arr[pos],arr[n]);
    // ans = arr[n];
    long double tempAns = arr[1];
    for (int i = 1; i < n; i++)
    {
        // if (pos == i)
        //     continue;
        tempAns = (tempAns*((long double)(i-1)/(long double)i) + arr[i]/(long double)i);
    }
    ans = ans + tempAns;
    // for (int i = 1; i <= n; i++)
    //     preAns[i] = preAns[i - 1] + arr[i];
    // for (int i = 1; i < n; i++)
    // {
    //     // double nowPre = preAns[i] / i
    //     ll nowPre = preAns[i];
    //     ll nowAft = preAns[n] - preAns[i];
    //     long double nowAns = nowPre/(long double)i + nowAft/(long double)(n-i);
    //     ans = max(ans, nowAns);
    //     // ans = max(ans, preAns[i]/i + preAns[n]-)
    // }
    cout << fixed << setprecision(10) << ans << endl;
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