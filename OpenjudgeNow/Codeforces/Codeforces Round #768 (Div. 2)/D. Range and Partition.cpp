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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, k;
vector<int> nums, oriNum;
int ansL, ansR, ans;

void work()
{
    cin >> n >> k;
    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    oriNum = nums;
    sort(nums.begin(), nums.end());
    ans = nums[n - 1] - nums[0] + 1;
    for (int l = nums[0]; l <= nums[n - 1]; l++)
    {
        int nowL = lower_bound(nums.begin(), nums.end(), l) - nums.begin();
        int len = (n + k + 1) / 2;
        if (nowL + len - 1 >= n)
            continue;
        int nl = nums[nowL];
        int nr = nums[nowL + len - 1];
        if (ans > nr - nl)
        {
            ans = nr - nl;
            ansL = nl;
            ansR = nr;
        }
    }
    cout << ansL << " " << ansR << endl;
    int nowCnt = 0;
    int nowK = 0;
    int nowPos = 1;
    for (int i = 0; i < n; i++)
    {
        if (oriNum[i] >= ansL && oriNum[i] <= ansR)
            nowCnt++;
        else
            nowCnt--;
        if (nowCnt == 1 && nowK+1 < k)
        {
            cout << nowPos << " " << i + 1 << endl;
            nowPos = i + 2;
            nowCnt = 0;
            nowK++;
        }
    }
    cout << nowPos << " " << n << endl;
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