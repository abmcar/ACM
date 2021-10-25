#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"

using namespace std;

const int Maxn = 1e5 + 10;
const ll Mod = 1e9 + 7;

int n, m, p1, s1, s2;
ll c[Maxn];
ll ans;
ll tot1, tot2, nowMin = 1e18;

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    cin >> m >> p1 >> s1 >> s2;
    int temp = 0;
    for (int i = 1; i < m; i++)
        tot1 += c[i] * (m - i);
    for (int i = m + 1; i <= n; i++)
        tot2 += c[i] * (i - m);
    if (p1 < m)
        tot1 += (ll)s1 * (m - p1);
    if (p1 > m)
        tot2 += (ll)s1 * (p1 - m);
}

void work()
{
    for (int i = 1; i < m; i++)
    {
        if (nowMin > std::abs(tot1 + (ll)s2 * (m - i) - tot2))
        {
            nowMin = std::abs(tot1 + (ll)s2 * (m - i) - tot2);
            ans = i;
        }
    }
    if (nowMin > std::abs(tot1 - tot2))
    {
        nowMin = std::abs(tot1 - tot2);
        ans = m;
    }
    for (int i = m + 1; i <= n; i++)
    {
        if (nowMin > std::abs(tot2 + (ll)s2 * (i - m) - tot1))
        {
            nowMin = std::abs(tot2 + (ll)s2 * (i - m) - tot1);
            ans = i;
        }
    }
    cout << ans;
}

int main()
{
    Buff;
    init();
    work();
    return 0;
}