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
    if (m == n - 1)
    {
        if (n == 4)
        {
            cout << -1 << endl;
            return;
        }
        unordered_map<int, bool> M;
        M[n - 1] = M[n - 2] = M[n - 3] = M[0] = M[1] = M[2] = true;
        cout << n - 2 << " " << n - 1 << endl;
        cout << 1 << " " << n - 3 << endl;
        cout << 0 << " " << 2 << endl;
        for (int i = 3; i < n - 1; i++)
        {
            if (M[i])
                continue;
            cout << i << " " << n - i - 1 << endl;
            M[i] = M[n - i - 1] = true;
        }
        return;
    }
    cout << m << " " << (n - 1) << endl;
    unordered_map<int, bool> M;
    M[m] = true;
    M[n - 1] = true;
    for (int i = 1; i < n - 1; i++)
    {
        if (M[i])
            continue;
        if (M[n - i - 1] == true)
        {
            M[i] = true;
            cout << 0 << " " << i << endl;
            continue;
        }
        M[i] = M[n - i - 1] = true;
        cout << i << " " << n - i - 1 << endl;
    }
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