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
    vector<int> nums(n), opts(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int ans = 0;
    int oriAns = 0;
    int st = 0;
    for (int i = 1; i < n - 1; i++)
    {
        opts[i] = (nums[i] - nums[i] % 2) / 2;
        nums[i] = nums[i] % 2;
        ans += opts[i];
        st += (nums[i] == 1);
    }
    oriAns = ans;
    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] == 0)
            continue;
        if (oriAns - opts[i] > 0 || (n >= 4 && opts[i] >= 2) || (n >= 4 && opts[i] && st))
        {
            // oriAns--;
            ans++;
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
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