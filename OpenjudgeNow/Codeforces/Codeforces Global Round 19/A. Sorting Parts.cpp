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
    vector<int> nums(n);
    vector<int> preMax(n), aftMin(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    preMax[0] = nums[0];
    aftMin[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++)
        preMax[i] = max(nums[i], preMax[i - 1]);
    for (int i = n - 2; i >= 0; i--)
        aftMin[i] = min(nums[i], aftMin[i + 1]);
    for (int i = n - 2; i >= 0; i--)
        if (preMax[i] > aftMin[i + 1])
        {
            // cout << preMax[i] << "    "<< aftMin[i] << endl;
            // cout <<i << endl;
            cout << "YES" << endl;
            return;
        }
    cout << "NO" << Endl;
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