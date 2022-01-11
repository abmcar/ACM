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
    cin >> n >> m;
    map<string, int> M;
    for (int i = 1; i <= n; i++)
    {
        string nowString;
        cin >> nowString;
        for (int j = 0; j + 1 < m; j++)
            M[nowString.substr(j, 2)] = i;
    }
    string oriString;
    cin >> oriString;
    for (int i = 0; i + 1 < m; i++)
    {
        if (M[oriString.substr(i, 2)] == 0)
        {
            if (i + 2 < m)
                if (M[oriString.substr(i + 1, 2)])
                    continue;
            // cout << oriString << endl;
            // cout << i << " " << oriString.substr(i, 2) << endl;
            // cout << i + 1 << " " << oriString.substr(i + 1, 2) << endl;
            cout << "-1" << endl;
            return;
        }
    }
    int cnt = 0;
    for (int i = 0; i + 1 < m; i++)
        if (M[oriString.substr(i, 2)])
            cnt++;
    cout << cnt << endl;
    for (int i = 0; i + 1 < m; i++)
        if (M[oriString.substr(i, 2)])
            cout << i + 1 << " " << i + 2 << " " << M[oriString.substr(i, 2)] << endl;
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