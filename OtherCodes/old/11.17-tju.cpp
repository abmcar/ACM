#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, n, tot, ans1, ans2;
int nums[100005];
int temp[100005];

int cal1(int x)
{
    return x * (x - 1) * (x - 2) * (x - 3) / 24;
}

int cal2(int x)
{
    return x * (x - 1) / 2;
}

signed main()
{
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        cin >> n;
        tot = ans1 = ans2 = 0;
        memset(nums, 0, sizeof nums);
        memset(temp, 0, sizeof temp);
        for (int i = 1; i <= n; i++)
        {
            int t1;
            cin >> t1;
            nums[t1]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (nums[i] >= 4)
                ans1 += cal1(nums[i]);
            if (nums[i] >= 2)
            {
                temp[i] = cal2(nums[i]);
                tot += temp[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (nums[i] < 2)
                continue;
            ans2 += temp[i] * (tot - temp[i]);
        }
        int ans = ans1 + ans2 / 2;
        cout << ans << endl;
    }
    return 0;
}
/* 
2
5
2 1 1 2 2
5
1 2 3 4 5
 */