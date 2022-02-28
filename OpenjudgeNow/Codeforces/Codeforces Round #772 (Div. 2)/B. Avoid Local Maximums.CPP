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

int t, n, m;

void work()
{
    cin >> n;
    vector<int> nums(n + 3);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    nums[0] = nums[n + 1] = 1e9;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        {
            nums[i + 1] = max(nums[i], nums[i + 2]);
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << nums[i] << " \n"[i == n];
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