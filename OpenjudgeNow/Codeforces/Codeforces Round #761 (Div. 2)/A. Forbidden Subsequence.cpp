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
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;
int t;

void work()
{
    string s1, s2;
    cin >> s1 >> s2;
    map<char, int> M;
    for (char it : s1)
        M[it]++;
    string ans = "";
    if (s2 == "abc" && M['a'] && M['b'] && M['c'])
    {
        for (int i = 1; i <= M['a']; i++)
            ans += 'a';
        for (int i = 1; i <= M['c']; i++)
            ans += 'c';
        for (int i = 1; i <= M['b']; i++)
            ans += 'b';
        for (char i = 'd'; i <= 'z'; i++)
            for (int j = 1; j <= M[i]; j++)
                ans += i;
    }
    else
        for (char i = 'a'; i <= 'z'; i++)
            for (int j = 1; j <= M[i]; j++)
                ans += i;
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