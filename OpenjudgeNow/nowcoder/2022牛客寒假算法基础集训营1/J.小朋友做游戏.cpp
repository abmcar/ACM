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
int ta, tb;

void work()
{
    cin >> ta >> tb >> n;
    vector<int> va(ta), vb(tb);
    for (int i = 0; i < ta; i++)
        cin >> va[i];
    for (int i = 0; i < tb; i++)
        cin >> vb[i];
    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end(), greater<int>());
    if (ta + min(ta, tb) < n)
    {
        cout << -1 << endl;
        return;
    }
    int pa, pb;
    pa = pb = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << ans << " " << pa << " " << pb << endl;
        if (pa == ta)
        {
            ans += vb[pb++];
            continue;
        }
        if (pb == tb || pb == n / 2)
        {
            ans += va[pa++];
            continue;
        }
        if (va[pa] > vb[pb])
            ans += va[pa++];
        else
            ans += vb[pb++];
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