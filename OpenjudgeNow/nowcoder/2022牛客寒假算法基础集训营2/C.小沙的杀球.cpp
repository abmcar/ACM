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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int x, a, b;
string oriS;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> x >> a >> b;
    cin >> oriS;
    int ans = 0;
    for (char it : oriS)
    {
        if (it == '1')
        {
            if (x >= a)
            {
                x -= a;
                ans++;
            }else
                x += b;
        }else
            x += b;
    }
    cout << ans << endl;
    return 0;
}