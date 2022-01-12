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

int t, n, m;

string getString(ll x)
{
    string nowString = "";
    while (x)
    {
        char nowChar = x % 2 + '0';
        x = x / 2;
        nowString = nowString + nowChar;
    }
    reverse(nowString.begin(), nowString.end());
    return nowString;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    ll t1, t2;
    cin >> t1 >> t2;
    cout << getString(t1) << endl
         << getString(t2) << endl;
    return 0;
}