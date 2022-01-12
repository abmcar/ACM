#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug
#define int long long

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;

void work()
{
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    ll tot = 0;
    for (int i = 1; i <= n; i++)
        cin >> b[i], tot += b[i];
    if (tot % (((1 + n) * n) / 2))
    {
        cout << "NO" << endl;
        return;
    }
    tot = tot / (((1 + n) * n) / 2);
    for (int i = 1; i <= n; i++)
    {
        a[i % n + 1] = (tot + b[i] - b[i % n + 1]) / n;
        if ((tot + b[i] - b[i % n + 1]) % n)
        {
            cout << "NO" << endl;
            return;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += a[i];
    if (cnt != tot)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] < 1 || a[i] > 1e9)
        {
            cout << "NO" << endl;
            return;
        }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
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