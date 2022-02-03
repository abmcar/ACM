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

int n, ans, totAns;
vector<int> nums, preAns;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    nums.resize(n);
    preAns.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i], totAns += nums[i];
    sort(nums.begin(), nums.end());
    preAns[0] = nums[0];
    for (int i = 1; i < n; i++)
        preAns[i] = preAns[i - 1] + nums[i];
    // // for (int it : nums)
    // //     cout << it << " ";
    // cout << endl;
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        int nowNum = nums[i];
        int targetNum = 1000 - nowNum;
        int nowPos = lower_bound(nums.begin(), nums.end(), targetNum) - nums.begin();
        // cout << lower_bound(nums.begin(), nums.end(), targetNum) - nums.begin() << endl;
        int nowAns = 1000 * nowPos - preAns[nowPos] - nowNum * nowPos + nums[nowPos];
        // cout << nowAns << endl;
        nowAns += -1000 * (n - nowPos) + (totAns - preAns[nowPos] + nums[nowPos]) + nowNum * (n - nowPos);
        // cout << nowAns << endl;
        ans += nowAns;
    }
    ans = ans / 2;
    for (int i = 0; i < n; i++)
        ans += abs(1000 - 2 * nums[i]) / 2;
    cout << ans << endl;
    return 0;
}