#include "bits/stdc++.h"

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
#define String string
// #define Debug

using namespace std;

const int Maxn = 1e6 + 10;
const ll Mod = 1e9 + 7;

int n, m;
int nums[Maxn];
int ans[Maxn];
vector<int> querys;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    for (int i = n-1; i >= 1; i--)
    {
        if (nums[i] > nums[i+1])
        {
            ans[i] = nums[i] - nums[i+1];
            nums[i] = nums[i+1];
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        cout << ans[temp] << endl;
    }
    return 0;
}