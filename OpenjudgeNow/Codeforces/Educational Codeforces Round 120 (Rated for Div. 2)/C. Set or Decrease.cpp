#include "bits/stdc++.h"

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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

ll t, n, k;

void work()
{
    cin >> n >> k;
    vector<int> nums(n + 1), preAns(n + 1);
    ll ans = 1e18;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    sort(nums.begin() + 1, nums.begin() + 1 + n);
    for (int i = 1; i <= n; i++)
        preAns[i] = preAns[i - 1] + nums[i];
    for (int i = n; i >= 1; i--)
    {
        ll nowTot = preAns[i] - nums[1];
        nowTot = k - nowTot;
        ll nowCnt = 1 + (n - i);
        ll nowLess = nowTot / nowCnt;
        while (nowLess * nowCnt > nowTot)
            nowLess--;
        // nowLess = max(nowLess, 0LL);
        ll nowAns = max(0LL,nums[1] - nowLess) + (n - i);
        ans = min(ans, nowAns);
        // cout << i << " " << nowCnt << " " << nowLess << " " << nowAns << endl;
    }
    ans = max(0LL, ans);
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