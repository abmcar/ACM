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

ll t, n;
ll ans = -253000000000000001;

void work()
{
    ans = -253000000000000001;
    priority_queue<ll, vector<ll>, less<ll>> Q1, Q3;
    priority_queue<ll, vector<ll>, greater<ll>> Q2, Q4;
    cin >> n;
    // Q1.push(0);
    // Q2.push(0);
    // Q3.push(0);1
    // Q4.push(0);
    int zero = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll nowTemp;
        cin >> nowTemp;
        if (nowTemp > 0)
        {
            Q1.push(nowTemp);
            Q4.push(nowTemp);
        }
        else if (nowTemp < 0)
        {
            Q2.push(nowTemp);
            Q3.push(nowTemp);
        }
        else
            zero++;

        if (Q1.size() > 11)
            Q1.pop();
        if (Q2.size() > 11)
            Q2.pop();
        if (Q3.size() > 11)
            Q3.pop();
        if (Q4.size() > 11)
            Q4.pop();
    }
    // cout << Q1.top() << " " << Q2.top() << endl;;
    vector<ll> V1, V2, V3, V4;
    for (ll i = 1; i <= 10; i++)
    {
        while (!Q1.empty() && Q1.top() == 0)
            Q1.pop();
        while (!Q2.empty() && Q2.top() == 0)
            Q2.pop();
        while (!Q3.empty() && Q3.top() == 0)
            Q3.pop();
        while (!Q4.empty() && Q4.top() == 0)
            Q4.pop();
        if (!Q1.empty())
        {
            V1.push_back(Q1.top());
            Q1.pop();
        }
        if (!Q2.empty())
        {
            V2.push_back(Q2.top());
            Q2.pop();
        }
        if (!Q3.empty())
        {
            V3.push_back(Q3.top());
            Q3.pop();
        }
        if (!Q4.empty())
        {
            V4.push_back(Q4.top());
            Q4.pop();
        }
    }
    if (V1.size() + V2.size() < 5)
    {
        cout << 0 << Endl;
        return;
    }
    // cout << "te" << endl;
    for (ll i = 0; i <= min(5,(int)V1.size()); i++)
    {

        if (i + V2.size() >= 5)
        {
            ll nowAns = 1;
            for (ll j = 0; j < i; j++)
                nowAns = nowAns * V1[j];
            for (ll j = 0; j < 5 - i; j++)
                nowAns = nowAns * V2[j];
            ans = max(ans, nowAns);
            // cout << i << " " << nowAns << endl;
        }
        if (i + V3.size() >= 5)
        {
            ll nowAns1 = 1;
            for (ll j = 0; j < i; j++)
                nowAns1 = nowAns1 * V1[j];
            for (ll j = 0; j < 5 - i; j++)
                nowAns1 = nowAns1 * V3[j];
            ans = max(ans, nowAns1);
            // cout << i << " " << nowAns1 << endl;
        }
        if (i + V2.size() >= 5)
        {
            ll nowAns = 1;
            for (ll j = 0; j < i; j++)
                nowAns = nowAns * V4[j];
            for (ll j = 0; j < 5 - i; j++)
                nowAns = nowAns * V2[j];
            ans = max(ans, nowAns);
            // cout << i << " " << nowAns << endl;
        }
        if (i + V3.size() >= 5)
        {
            ll nowAns1 = 1;
            for (ll j = 0; j < i; j++)
                nowAns1 = nowAns1 * V4[j];
            for (ll j = 0; j < 5 - i; j++)
                nowAns1 = nowAns1 * V3[j];
            ans = max(ans, nowAns1);
            // cout << i << " " << nowAns1 << endl;
        }
    }
    if (zero != 0)
        ans = max((ll)0, ans);
    if (ans == -253000000000000001)
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