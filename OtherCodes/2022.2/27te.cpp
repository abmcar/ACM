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

int n;
vector<pair<int, string>> V;
vector<bool> vis;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    V.push_back({0, "123"});
    for (int i = 1; i <= n; i++)
    {
        int opt;
        string arg1;
        cin >> opt >> arg1;
        V.push_back({opt, arg1});
    }
    vis.resize(n + 1);
    for (int i = 1; i * 2 <= n; i++)
    {
        int p1, p2;
        for (int j = 1; j <= n; j++)
        {
            if (V[j].first == 1)
                continue;
            if (vis[j])
                continue;
            p1 = j;
            vis[j] = true;
            break;
        }
        for (int j = n; j >= 1; j--)
        {
            if (V[j].first == 0)
                continue;
            if (vis[j])
                continue;
            p2 = j;
            vis[j] = true;
            break;
        }
        cout << V[p1].second << " " << V[p2].second << endl;
    }
    return 0;
}