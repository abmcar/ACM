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
string s, ts;

void work()
{
    cin >> n >> m;
    cin >> s >> ts;
    vector<int> f(32);
    f[0] = 1;
    for (auto it : s)
    {
        for (int j = 0; char itt : ts)
        {
            j++;
            if (it == itt && f[j-1] && f[j-1] >= f[j])
                f[j]++;
        }
    }
    cout << f[ts.size()] << endl;
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