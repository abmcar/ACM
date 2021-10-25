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
#define Inf ll_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

String llToString(ll num)
{
    String nowString = "";
    while (num)
    {
        if (num % 2)
            nowString = nowString + '1';
        else
            nowString = nowString + '0';
        num = num / 2;
    }
    reverse(nowString.begin(),nowString.end());
    return nowString;
}

ll stringToll(String nowString)
{
    ll num = 0;
    ll cnt = 0;
    for (ll i = 0; i < nowString.size(); i++)
    {
        if (nowString[i] == '1')
            num += (1 << cnt);
        cnt++;
    }
    return num;
}

ll n;
ll tot;

signed main()
{
    // cout << llToString(8) << " " << stringToll("0001");
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        tot += stringToll(llToString(temp));
    }
    cout << tot << endl;
    return 0;
}