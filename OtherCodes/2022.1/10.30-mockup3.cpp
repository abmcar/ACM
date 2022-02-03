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

int n, m, ans;
vector<int> g[Maxn];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    for (int i = 0; i <= (1LL << n); i++)
    {
        vector<int> nowStatus(n + 1);
        for (int j = 0; (1LL << j) <= i; j++)
            nowStatus[j + 1] = i & (1LL << j);
        int nowAns = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!nowStatus[j])
                continue;
            nowAns++;
            for (int it : g[j])
                nowStatus[it] = false;
        }
        ans = max(ans,nowAns);
    }
    cout << ans << endl;
    return 0;
}