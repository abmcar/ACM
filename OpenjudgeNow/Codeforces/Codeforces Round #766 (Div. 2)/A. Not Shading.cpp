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
char bd[1234][1234];

void work()
{
    cin >> n >> m;
    int t1, t2;
    cin >> t1 >> t2;
    for (int i = 1; i <= n; i++)
        cin >> bd[i]+1;
    bool ok = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (bd[i][j] == 'B')
                ok = false;
    if (ok)
    {
        cout << -1 << endl;
        return;
    }
    if (bd[t1][t2] == 'B')
    {
        cout << 0 << endl;
        return;
    }
    ok = true;
    for (int i = 1; i <= n; i++)
        if (bd[i][t2] == 'B')
            ok = false;
    for (int j = 1; j <= m; j++)
        if (bd[t1][j] == 'B')
            ok = false;
    if (!ok)
        cout << 1 << endl;
    else
        cout << 2 << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> t;
    while(t--)
        work();
    return 0;
}