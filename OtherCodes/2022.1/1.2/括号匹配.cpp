#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int ans = 0;
    string s;
    cin >> s;
    bool ok = true;
    stack<int> S;
    for (char it : s)
    {
        if (it == '(')
        {
            S.push(1);
            ans++;
        }
        if (it == ')')
        {
            if (S.empty())
            {
                ok = false;
                break;
            }
            S.pop();
        }
    }
    if (S.size())
        ok = false;
    if (ok)
        cout << ans << endl;
    else
        cout << "NO" << endl;
    return 0;
}