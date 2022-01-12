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

int t, n, m;

void work()
{
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    int ans1 = nums[1];
    int ans2 = nums[2];
    bool ok1, ok2;
    ok1 = ok2 = true;
    for (int i = 3; i <= n; i += 2)
        ans1 = __gcd(ans1, nums[i]);
    for (int i = 4; i <= n; i += 2)
        ans2 = __gcd(ans2, nums[i]);
    for (int i = 2; i <= n; i += 2)
        if (nums[i] % ans1 == 0)
            ok1 = false;
    for (int i = 1; i <= n; i += 2)
        if (nums[i] % ans2 == 0)
            ok2 = false;
    if (ok1)
    {
        cout << ans1 << endl;
        return;
    }
    if (ok2)
    {
        cout << ans2 << endl;
        return;
    }
    cout << 0 << endl;
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