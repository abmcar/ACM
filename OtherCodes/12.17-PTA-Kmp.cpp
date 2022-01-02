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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, m, ans;
int ne[Maxn];
char s[Maxn], p[Maxn];

int getNum(int x)
{
    if (ne[x] == 0)
        return x;
    ne[x] = getNum(ne[x]);
    return ne[x];
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> p + 1;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    ans = (1 + n) * n / 2;
    for (int i = 1; i <= n; i++)
        ans -= getNum(i);
    cout << ans << endl;
    return 0;
}