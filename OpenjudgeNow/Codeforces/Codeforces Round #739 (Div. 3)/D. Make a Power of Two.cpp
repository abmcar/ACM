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
const ll Mod = 1e9 + 7;

ll t;
ll cnt = 0;
String preStrings[65];

String toString(ll num)
{
    String nowString = "";
    while (num)
    {
        char nowChar = num % 10 + '0';
        num = num / 10;
        nowString = nowChar + nowString;
    }
    return nowString;
}

ll checkDif(String a, String b)
{
    // swap(a,b);
    ll nowPos = 0;
    for (ll i = 0; i < a.size(); i++)
        if (a[i] == b[nowPos])
            nowPos++;
    // cout << nowPos << endl;
    if (nowPos == b.size()+1)
        return a.size() - b.size();
    else    
        return a.size() - nowPos + (b.size() - nowPos);
}

void work()
{
    ll num, ans;
    ans = 1e9;
    cin >> num;
    String nowString = toString(num);
    for (ll i = 1; i <= cnt; i++)
        ans = min(ans,checkDif(nowString,preStrings[i]));
    cout << ans << endl;
}

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    ll nowNode = 1;
    while (nowNode <= 2e18)
    {
        preStrings[++cnt] = toString(nowNode);
        // cout << nowNode << endl;
        nowNode = nowNode * 2;
    }
    // cout << checkDif("687194767","67108864");
    cin >> t;
    while (t--)
        work();
    return 0;
}