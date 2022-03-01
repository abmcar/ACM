#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t, n, ans;
vector<int> nums;

void work()
{
    ans = 1e9;
    int nowMin = 1e9;
    int totAns = 0;
    cin >> n;
    nums.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        totAns += nums[i];
        nowMin = min(nums[i], nowMin);
    }
    vector<int> preAns(n + 1);
    for (int i = 1; i <= n; i++)
        preAns[i] = preAns[i - 1] + nums[i];
    for (int nowTarget = max(1, nowMin); nowTarget <= totAns; nowTarget++)
    {
        if (totAns % nowTarget)
            continue;
        int nowAns = 0;
        int cnt = 0;
        bool ok = true;
        for (int k = 1; k <= n; k++)
        {
            nowAns += nums[k];
            if (preAns[k] - cnt * nowTarget == nowTarget)
            {
                nowAns = 0;
                cnt++;
            }
        }
        if (!ok || nowAns)
            continue;
        ans = n - cnt;
        break;
    }
    if (totAns == 0)
        ans = 0;
    cout << ans << endl;
}

signed main()
{
    cin >> t;
    while (t--)
        work();
    return 0;
}