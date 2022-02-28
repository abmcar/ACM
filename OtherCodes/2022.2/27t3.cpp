#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k, ans;
vector<int> nums;
string oriColor;

signed main()
{
    ans = 1e15;
    cin >> n >> k;
    nums.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    cin >> oriColor;
    for (int i = 1; i <= n; i++)
        if (oriColor[i - 1] == 'R')
            nums[i] = 0;
    int nowAns = 0;
    for (int i = 1; i <= k; i++)
        nowAns += nums[i];
    ans = nowAns;
    for (int i = 2; i + k - 1 <= n; i++)
    {
        ans = min(ans, nowAns);
        nowAns = nowAns - nums[i - 1] + nums[i + k - 1];
        ans = min(ans, nowAns);
    }
    cout << ans << endl;
    return 0;
}