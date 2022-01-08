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
int father[Maxn];

void work()
{
    cin >> n;
    vector<int> V;
    vector<pair<int, int>> d[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int opt, arg1, arg2;
        cin >> opt;
        if (opt == 1)
        {
            cin >> arg1;
            V.push_back(arg1);
        }
        else
        {
            cin >> arg1 >> arg2;
            if (V.size() == 0)
                continue;
            d[V.size() - 1].push_back({arg1, arg2});
        }
    }
    for (int i = 1; i <= Maxn; i++)
        father[i] = i;
    for (int i = V.size() - 1; i >= 0; i--)
    {
        for_each(d[i].rbegin(), d[i].rend(), [](auto it)
                 { father[it.first] = father[it.second]; });
        V[i] = father[V[i]];
    }
    for_each(V.begin(), V.end(), [](int it)
             { cout << it << " "; });
    cout << endl;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    // cin >> t;
    // while (t--)
    work();
    return 0;
}