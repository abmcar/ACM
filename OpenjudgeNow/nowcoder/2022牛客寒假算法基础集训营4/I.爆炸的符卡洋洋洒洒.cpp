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

int n, k;
vector<int> value(1234), weight(1234);
vector<int> f[3];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> k;
    f[1].resize(1234);
    f[0].resize(1234);
    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> value[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (f[(i + 1) % 2][j] == 0 && j != 0)
            {
                f[i % 2][(j + weight[i]) % k] = f[(i + 1) % 2][(j + weight[i]) % k];
                continue;
            }
            f[i % 2][(j + weight[i]) % k] = max(f[(i + 1) % 2][(j + weight[i]) % k], f[(i + 1) % 2][j] + value[i]);
        }
    }
    if (f[n % 2][0] == 0)
        f[n % 2][0] = -1;
    cout << f[n % 2][0] << endl;
    return 0;
}