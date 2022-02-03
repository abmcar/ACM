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

int n, m, k;
int x;
int minn, maxn;

signed main()
{
    // cout << 2000000000LL * 2000000001LL / 2 << endl;
    // cout << 1000000000LL * 1000000001LL / 2 << endl;
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m >> k;
    while (k--)
    {
        cin >> x;
        cout << x % n << " " << x / n << endl;
    }
    return 0;
}