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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int t, n, k;
vector<int> pre(Maxn * 3, 1e9);

void work()
{
    vector<int> b, c, f;
    cin >> n >> k;
    b.resize(n + 1);
    c.resize(n + 1);
    f.resize(k + 1);
    int temp = 0;
    int tot = 0;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i], tot += c[i];
    for (int i = 1; i <= n; i++)
        temp += pre[b[i]];
    if (k >= temp)
    {
        cout << tot << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        for (int j = k; j >= pre[b[i]]; j--)
            f[j] = (f[j] > (f[j - pre[b[i]]] + c[i])) ? f[j] : (f[j - pre[b[i]]] + c[i]);
    cout << f[k] << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    pre[1] = 0;
    for (int i = 1; i <= 1e3; i++)
        for (int j = 1; j <= i; j++)
            pre[i + i / j] = ((pre[i + i / j] < (pre[i] + 1)) ? pre[i + i / j] : pre[i] + 1);
    cin >> t;
    while (t--)
        work();
    return 0;
}