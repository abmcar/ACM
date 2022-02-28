#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

void toInt(string s)
{
    ll x = 0;
    // reverse(s.begin(),s.end());
    for (int i = 0; i < s.size(); i++)
    {
        x *= 2;
        x = x + s[i] - '0';
    }
    cout << x << endl;
}

void print(ll x)
{
    // cout << x << " ";
    string s;
    while (x)
    {
        s = (char)('0' + x % 2) + s;
        x = x / 2;
    }
    // cout << s << endl;
    toInt(s + s);
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int x;
    cin >> x;
    print(x);
    return 0;
}