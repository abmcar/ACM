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
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end(), greater<int>());
    int ans = 0;
    map<int, int> M;
    for (int i = 0; i < m * 2; i++)
        M[nums[i]]++;
    for (auto it : M)
    {
        if (it.second > m)
            ans = it.second - m;
    }
    // cout << ans << " pore" << endl;
    for (int i = m * 2; i < n; i++)
        ans += nums[i];
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