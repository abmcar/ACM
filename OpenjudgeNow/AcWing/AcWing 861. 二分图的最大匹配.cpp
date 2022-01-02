#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int n1, n2, m, ans;
vector<int> g[Maxn];
int match[Maxn];
map<int, bool> ok;

bool tryMatch(int x)
{
    for (int nextNode : g[x])
    {
        if (ok[nextNode])
            continue;
        ok[nextNode] = true;
        if (match[nextNode] == 0 || tryMatch(match[nextNode]))
        {
            match[nextNode] = x;
            return true;
        }
    }
    return false;
}

signed main()
{
    // Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n1 >> n2 >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
    }
    for (int i = 1; i <= n1; i++)
    {
        ok.clear();
        if (tryMatch(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}