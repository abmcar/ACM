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
    // cin >> n;
    string oriString;
    cin >> oriString;
    n = oriString.size();
    vector<int> nums(n + 1, 0);
    nums[0] = 1;
    bool fir = true;
    for (int i = 0; i < oriString.size(); i++)
    {
        if (oriString[i] == 'E')
            nums[i + 1] = nums[i];
        else
        {
            if (fir)
            {
                fir = false;
                nums[i + 1] = !nums[i];
            }
            else
                nums[i + 1] = nums[0];
        }
    }
    // for (int i = 0; i <= n; i++)
    //     cout << nums[i];
    // cout << endl;
    if (nums[n] == nums[0])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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