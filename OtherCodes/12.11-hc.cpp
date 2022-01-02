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

int n, m;
int t[1234][1234];
int nums[1234];
int ans;
int ansn[1234];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            nums[j] = t[j][i];
        sort(nums + 1, nums + 1 + n);
        int mid = nums[(n + 1) / 2];
        for (int j = 1; j <= n; j++)
            ans += abs(nums[j] - mid);
        ansn[i] = mid;
    }
    cout << ans << endl;
    for (int i = 1; i <= m; i++)
        cout << ansn[i] << " ";
    return 0;
}