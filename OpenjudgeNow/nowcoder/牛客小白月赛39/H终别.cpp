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

ll n;
ll hp[Maxn], oriHp[Maxn];
ll cost[Maxn];
ll tot;

void get()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> hp[i], oriHp[i] = hp[i];
}

void work()
{

    for (ll i = 1; i <= n; i++)
    {

        if (hp[i])
        {
            if (i == n)
            {
                cost[i] += hp[i];
                break;
            }
            cost[i + 1] += hp[i];
            hp[i + 2] = max(0LL, hp[i + 2] - hp[i]);
            hp[i + 1] = max(0LL, hp[i + 1] - hp[i]);
            hp[i] = 0;
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << cost[i] << " ";
    // cout << Endl;
    ll nowPos;
    ll nowMax = 0;
    ll nowMax1 = 0;
    for (ll i = 1; i <= n; i++)
    {

        if (cost[i] + cost[i + 1] > nowMax)
        {
            nowMax1 = hp[i - 1] + hp[i + 2];
            nowMax = cost[i] + cost[i + 1];
            nowPos = i;
        }
        else if (cost[i] + cost[i + 1] == nowMax)
        {
            if (hp[i - 1] + hp[i + 2] < nowMax1)
            {
                nowMax = cost[i] + cost[i + 1];
                nowPos = i;
                nowMax1 = hp[i - 1] + hp[i + 2];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cost[i] = 0, hp[i] = oriHp[i];
    hp[nowPos] = 0;
    hp[nowPos + 1] = 0;
    for (ll i = 1; i <= n; i++)
    {

        if (hp[i])
        {
            if (i == n)
            {
                cost[i] += hp[i];
                break;
            }
            cost[i + 1] += hp[i];
            hp[i + 2] = max(0LL, hp[i + 2] - hp[i]);
            hp[i + 1] = max(0LL, hp[i + 1] - hp[i]);
            hp[i] = 0;
        }
    }
    //     for (int i = 1; i <= n; i++)
    //     cout << cost[i] << " ";
    // cout << Endl;
    for (ll i = 1; i <= n; i++)
        // cout << cost[i] << " ", tot += cost[i];
        tot += cost[i];

    // cout << endl;
    cout << tot;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    get();
    work();
    return 0;
}