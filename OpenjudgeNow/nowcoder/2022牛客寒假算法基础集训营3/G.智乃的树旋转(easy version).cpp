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

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int n;
int lc[Maxn], rc[Maxn], fa[Maxn];
int alc[Maxn], arc[Maxn], afa[Maxn];
int root;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lc[i] >> rc[i];
        fa[lc[i]] = i;
        fa[rc[i]] = i;
    }
    root = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> alc[i] >> arc[i];
        afa[alc[i]] = i;
        afa[arc[i]] = i;
    }
    while (afa[root] != 0)
        root = afa[root];
    // cout << 1 << endl;
    for (int i = 1; i <= n; i++)
    {
        if (i == root)
            continue;
        if (rc[i] != 0 && afa[i] == rc[i])
        {
            cout << 1 << endl;
            cout << i << endl;
            return 0;
        }
        if (lc[i] != 0 && afa[i] == lc[i])
        {
            cout << 1 << Endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 <<  endl;
    return 0;
}