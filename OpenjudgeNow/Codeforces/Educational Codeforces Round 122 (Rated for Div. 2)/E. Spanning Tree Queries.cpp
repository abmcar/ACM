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
int p, k, a, b;

struct Edge
{
    int from, to;
    int val;
}edge[333];

void work()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> edge[i].from >> edge[i].to >> edge[i].val;
    sort(edge+1,edge+1+m,[](Edge ta, Edge tb)
    {
        return ta.val < tb.val;
    });
    
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