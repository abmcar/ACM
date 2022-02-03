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
const ll Mod = 998244353;
#define int long long
int t, n, m;

void work()
{
    string s1, s2;
    cin >> s1 >> s2;
    int a = s1.size();
    int b = s2.size();
    int nextV = 0;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    while (s1.size() < s2.size())
        s1 = s1 + "0";
    while (s2.size() < s1.size())
        s2 = s2 + "0";
    int ans = 0;
    int cnt = 1;
    for (int i = 0; i < s1.size(); i++)
    {
        int nowVal = (int)(s1[i] - '0') * b + (int)(s2[i] - '0') * a;
        nowVal = nowVal * cnt % Mod;
        cnt = cnt * 10 % Mod;
        ans = ans + nowVal;
        ans = ans % Mod;
    }
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