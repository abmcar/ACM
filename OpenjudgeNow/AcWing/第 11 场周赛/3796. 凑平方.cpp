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
// #include <bits/extc++.h>
#include <bits/stdc++.h>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

// ll V[(ll)2e5+10][10];
ll pos;
ll ans;

void dfs(ll nowX, ll nowDeep)
{
    // cout << nowX << " " << nowDeep << endl;
    if (nowX == 0)
        return;
    if (nowDeep >= ans)
        return;
    if (nowX == (ll)sqrt(nowX) * (ll)sqrt(nowX))
    {
        // cout << nowX << " !" << ans << " " << sqrt(nowX) << endl;
        ans = min (ans ,nowDeep);
    }
    for (ll i = 1; i <= nowX; i = i * 10)
    {
        ll preNum = nowX / i;
        if (preNum - preNum%(preNum/10) == preNum)
            continue;
        // if (preNum * i == nowX - nowX % i)
        //     continue;
        ll tempNum = nowX / (i * 10) * i + nowX % i;
        if (tempNum == 0)
            continue;
        dfs(tempNum, nowDeep + 1);
    }
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        ll temp;
        ans = 1e9;
        cin >> temp;
        dfs(temp, 0);
        if (ans == 1e9)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}
//1111 11 11 123450000