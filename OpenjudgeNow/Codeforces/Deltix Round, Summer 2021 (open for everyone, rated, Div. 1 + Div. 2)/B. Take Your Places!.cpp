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
using namespace __gnu_pbds;

const ll Maxn = 1e7 + 10;
const ll Mod = 1e12 + 7;

ll t, n;
ll num[Maxn];

void work()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> num[i];
    ll nowAns = 1e12;
    vector<ll> v1, v2;
    for (ll i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            if (num[i] % 2 == 0)
                v1.push_back(i);
        }
        else if (num[i] % 2)
            v2.push_back(i);
    }
    if (v1.size() == v2.size())
    {
        nowAns = 0;
        for (ll i = 0; i < v1.size(); i++)
            nowAns += abs(v1[i] - v2[i]);
    }
    v1.clear();
    v2.clear();
    for (ll i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            if (num[i] % 2)
                v1.push_back(i);
        }
        else if (num[i] % 2 == 0)
            v2.push_back(i);
    }
    ll tempAns = 1e12;
    if (v1.size() == v2.size())
    {
        tempAns = 0;
        for (ll i = 0; i < v1.size(); i++)
            tempAns += abs(v1[i] - v2[i]);
    }
    nowAns = min(nowAns,tempAns);
    if (nowAns == 1e12)
        nowAns = -1;
    cout << nowAns << endl;
    // cout << nowAns << " " << tempAns << endl;
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