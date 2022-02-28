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
string s;
bool dp[2][11][2];

void work()
{
    cin >> n;
    cin >> s;
    int t1, t2;
    bool t3 = false;
    t1 = t2 = 0;
    for (char it : s)
        if (it == 'w')
            t2++;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == 'b')
            t3 = true;
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