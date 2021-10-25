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

ll getValue(char nowChar)
{
    if (nowChar >= '0' && nowChar <= '9')
        return nowChar - '0';
    if (nowChar >= 'A' && nowChar <= 'Z')
        return nowChar-'A'+10;
    if (nowChar >= 'a' && nowChar <= 'z')
        return nowChar-'a'+36;
    if (nowChar == '-')
        return 62;
    if (nowChar == '_')
        return 63;
}

ll getValue(String string)
{
    ll nowValue = getValue(string[0]);
    for (ll i = 1; i < string.size(); i++)
        nowValue = nowValue & getValue(string[i]);
    return nowValue;
}


ll quickPow(ll base, ll x)
{
    ll nowBase = 1;
    while (x)
    {
        if (x % 2)
        {
            nowBase = nowBase * base % Mod;
            x = x - 1;
            continue;
        }
        base = base * base % Mod;
        x = x / 2;
    }
    return nowBase % Mod;
}
String oriString;
ll num1, num0;
ll stringValue;
ll ans;
map<ll,ll> M;

ll getNum(int num)
{
    return quickPow(3,num);
}


int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif  
    // cout << (1<< 1);
    cin >> oriString;
    // stringValue = getValue(oriString);
    ans = 1;
    for (char nowChar : oriString)
    {
        int charValue = getValue(nowChar);
        num1 = num0 = 0;
        for (ll i = 0; (1 << i) < 64; i++)
            if ((1 << i) & charValue)
                num1++;
            else
                num0++;
        ll nowNum = getNum(num0);
        ans = ans * nowNum % Mod;
    }
    cout << ans << endl;
    // cout << stringValue;
    // cout << num0 << endl;
    // ans = 1;
    // for (int i = 1; i <= num0; i++)
    //     ans = ans*(quickPow(2,oriString.size()*2)-2) % Mod;
    // cout << ans << endl;
    return 0;
}