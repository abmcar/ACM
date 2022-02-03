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
int a, b;
void work()
{
    cin >> a >> b;
    int ans = b - a;
    for (int a1 = a; a1 < b; a1++)
    {
        int b1 = 0;
        for (int i = 23; i >= 0; i--)
        {
            if (b & (1 << i))
                b1 = b1 | (1 << i);
            else
            {
                if (a1 & (1 << i))
                {
                    b1 = b1 | (1 << i);
                    break;
                }
            }
        }
        ans = min(ans, a1 - a - b + (a1 | b1) + 1);
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