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
ll ans = -243000000000000001;

void work()
{
    ans = -243000000000000001;
    priority_queue<ll, vector<ll>, less<ll>> Q1, Q2;
    priority_queue<ll, vector<ll>, greater<ll>> Q3, Q4;
    cin >> n;
    ll zero = 0;
    ll t1, t2;
    t1 = t2 = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll nowNum;
        cin >> nowNum;
        if (nowNum > 0)
        {
            t1++;
            Q1.push(nowNum);
            Q3.push(nowNum);
        }else if (nowNum < 0)
        {
            t2++;
            Q2.push(nowNum);
            Q4.push(nowNum);
        }else
            zero++;
        if (Q1.size() > 5)
            Q1.pop();
        if (Q2.size() > 5)
            Q2.pop();
        if (Q3.size() > 5)
            Q3.pop();
        if (Q4.size() > 5)
            Q4.pop();
    }
    vector<ll> V1,V2,V3,V4;
    while (!Q1.empty())
    {
        V1.push_back(Q1.top());
        Q1.pop();
        V3.push_back(Q3.top());
        Q3.pop();
    }
    while (!Q2.empty())
    {
        V2.push_back(Q2.top());
        Q2.pop();
        V4.push_back(Q4.top());
        Q4.pop();
    }
    // V3.reserve(V3.size());
    reverse(V3.begin(),V3.end());
    reverse(V2.begin(),V2.end());
    for (ll i = 0; i <= V1.size(); i++)
    {
        // cout << "v1 " << V1.size() << " v2 " << V2.size() << endl;
        if (i + V2.size() >= 5)
        {
            ll nowAns = 1;
            for (ll j = 0; j < i; j++)
                nowAns = nowAns * V1[j];
            for (ll j = 0; j < 5-i; j++)
                nowAns = nowAns * V2[j];
            ans = max(ans,nowAns);
            // cout << ans << endl;
            nowAns = 1;
            for (ll j = 0; j < i; j++)
                nowAns = nowAns * V1[j];
            for (ll j = 0; j < 5-i; j++)
                nowAns = nowAns * V4[j];
            ans = max(ans,nowAns);

            nowAns = 1;
            for (ll j = 0; j < i; j++)
                nowAns = nowAns * V3[j];
            for (ll j = 0; j < 5-i; j++)
                nowAns = nowAns * V4[j];
            ans = max(ans,nowAns);
            
            nowAns = 1;
            for (ll j = 0; j < i; j++)
                nowAns = nowAns * V3[j];
            for (ll j = 0; j < 5-i; j++)
                nowAns = nowAns * V2[j];
            ans = max(ans,nowAns);
        }
    }
    // cout << ans << endl;
    if (zero != 0)
        ans = max((ll)0,ans);
    if (ans == -243000000000000001)
        ans = 0;
    for (int i = 0; i < V1.size(); i++)
        cout << V1[i] << " ";
    cout << Endl;
    for (int i = 0; i < V2.size(); i++)
        cout << V2[i] << " ";
    cout << Endl;
    for (int i = 0; i < V3.size(); i++)
        cout << V3[i] << " ";
    cout << Endl;
    for (int i = 0; i < V4.size(); i++)
        cout << V4[i] << " ";
    cout << Endl;
    cout << ans << endl;
}

int main()
{
    // ll temp = 3e3;
    // cout << temp*temp*temp*temp*temp << endl;
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