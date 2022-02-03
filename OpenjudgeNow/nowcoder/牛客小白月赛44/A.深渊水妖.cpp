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
#define int long long
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;
int t, n, m;

void work()
{
    map<int, vector<pair<int, int>>> M;
    cin >> n;
    vector<int> nums(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    int strPos = 1;
    int maxVal = 0;
    for (int i = 1; i <= n; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            maxVal = max(maxVal, nums[i] - nums[strPos]);
            M[nums[i] - nums[strPos]].push_back({strPos, i});
            strPos = i + 1;
        }
    }
    for (auto it : M[maxVal])
        cout << it.first << " " << it.second << " ";
    cout << endl;
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