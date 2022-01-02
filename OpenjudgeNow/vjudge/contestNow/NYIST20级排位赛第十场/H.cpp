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

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int n, k;
String oriString;
int nums[Maxn];

bool check(int nowMid)
{
    for (int i = 1; i <= n; i++)
        if (oriString[i - 1] == '0')
            if (nums[min(n,i + nowMid)] - nums[max(0, i - nowMid - 1)] >= k + 1)
            {
                // cout << i << " " << nowMid << " " << k << endl;
                return true;
            }
    return false;
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> k;
    cin >> oriString;
    for (int i = 1; i <= n; i++)
    {
        nums[i] = nums[i - 1];
        if (oriString[i - 1] == '0')
            nums[i]++;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << nums[i] << " ";
    // cout << endl;
    int l = 1;
    int r = n;
    int ans;
    while (l <= r)
    {
        // cout << l << " " << r << endl;
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}