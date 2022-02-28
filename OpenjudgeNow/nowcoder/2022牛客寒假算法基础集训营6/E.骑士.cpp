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
    int ans = 0;
    vector<int> a, b, h;
    cin >> n;
    a.resize(n);
    b.resize(n);
    h.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> h[i];
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    vector<int> t = a;
    sort(t.begin(), t.end(), greater());
    int maxAtk = t[0];
    int sedAtk = t[1];
    bool fir = true;
    for (int i = 0; i < n; i++)
    {
        if (fir && maxAtk == a[i])
        {
            fir = false;
            ans += max(0LL, (sedAtk - b[i]) - h[i] + 1);
        }
        else
        {
            ans += max(0LL, (maxAtk - b[i]) - h[i] + 1);
        }
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