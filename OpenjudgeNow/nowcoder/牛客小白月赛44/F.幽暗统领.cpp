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
#define int long long
const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;

void work()
{
    cin >> n;
    int maxn = 0;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        maxn = max(maxn, nums[i]);
    }
    maxn--;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += max(0LL, nums[i] - (maxn / 2));
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