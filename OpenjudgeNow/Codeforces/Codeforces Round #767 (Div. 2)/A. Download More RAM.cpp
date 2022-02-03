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
    int ans;
    cin >> n >> ans;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<pair<int, int>> V;
    for (int i = 0; i < n; i++)
        V.push_back({a[i], b[i]});
    sort(V.begin(), V.end());
    for (int i = 0; i < n; i++)
    {
        // cout << V[i].first << " " << V[i].second << " " << ans << endl;
        if (ans >= V[i].first)
            ans += V[i].second;
        else
            break;
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