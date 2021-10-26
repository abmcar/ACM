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

const ll Maxn = 1e4 + 10;
const ll Mod = 1e9 + 7;

ll t, n;
String strings[Maxn];
ll nowPos[Maxn];
String oriString;
unordered_map<char, bool> M;


bool check(int num)
{
    for (int i = 0; i < oriString.size(); i++)
    {
        unordered_map<char,bool> nowM;
        int len = min((int)oriString.size(),i+num);
        // for (int j = i; j < len+i; j++)
        //     nowM[oriString[j]] = true;
        
        if (nowM.size() == M.size())
            return true;
        // cout << "  num " << num << " " << nowM.size() << endl;
    }
    return false;
}

void work()
{
    M.clear();
    ll maxLen = 0;
    ll totLen = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> strings[i], maxLen = max(maxLen, (ll)strings[i].size()), nowPos[i] = 0, totLen += strings[i].size();
    oriString = "";
    for (int i = 1; i <= n; i++)
    for (char it : strings[i])
        M[it] = true;
    for (int k = 1; k <= maxLen*2.5; k++)
    for (ll i = 1; i <= n; i++)
    {
        oriString = oriString + strings[i][nowPos[i]];
        nowPos[i]++;
        if (nowPos[i] == strings[i].size())
            nowPos[i] = 0;
    }
    // cout << M.size() << endl;
    // cout << oriString << " ooo" << endl;
    ll l = 1;
    ll r = totLen;
    ll ans;
    // cout << M.size() << endl;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        // cout << l << " " << r << " " << mid << endl;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }else
            l = mid + 1;
    }
    cout << ans << endl;
    // ori
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