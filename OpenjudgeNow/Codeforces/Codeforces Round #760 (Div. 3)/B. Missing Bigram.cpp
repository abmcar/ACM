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

void work()
{
    map<char, vector<string>> M;
    cin >> n;
    string ans;
    cin >> ans;
    for (int i = 2; i <= n - 2; i++)
    {
        string nowString;
        cin >> nowString;
        if (*nowString.begin() != *ans.rbegin())
            ans = ans + *nowString.begin();
        ans = ans + *nowString.rbegin();
    }
    if (ans.size() != n)
        ans = ans + "b";
    cout << ans << endl;
}

signed main()
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