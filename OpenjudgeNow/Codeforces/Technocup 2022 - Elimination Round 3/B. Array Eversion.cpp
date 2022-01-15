#include <bits/stdc++.h>

#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
// #define endl "\n"
// #define Endl "\n"
#define String string
// #define Debug

using namespace std;
// using namespace __gnu_pbds;

const int Maxn = 1e7 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;
int ans;
int nums[Maxn];

void work()
{
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    while (1)
    {
        vector<int> v1, v2;
        for (int i = 1; i < n; i++)
            if (nums[n] >= nums[i])
                v1.push_back(nums[i]);
            else
                v2.push_back(nums[i]);
        int cnt = 1;
        bool ok = true;
        for (int i = 0; i < v1.size(); i++)
        {
            if (ok && nums[cnt] != v1[i])
                ok = false;
            nums[cnt++] = v1[i];
        }
        if (ok && nums[cnt] != nums[n])
            ok = false;
        nums[cnt++] = nums[n];
        for (int i = 0; i < v2.size(); i++)
        {
            if (ok && nums[cnt] != v2[i])
                ok = false;
            nums[cnt++] = v2[i];
        }
        // for (int i = 1; i <= n; i++)
        //     cout << nums[i] << " ";
        // cout << endl;
        if (ok)
            break;
        ans++;
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