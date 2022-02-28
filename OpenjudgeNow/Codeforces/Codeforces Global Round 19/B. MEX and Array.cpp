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

int t, n, ans;

int getValue(vector<int> nowNums)
{
    int nowAns = nowNums.size();
    for (int it : nowNums)
        if (it == 0)
            nowAns++;
    return nowAns;
}

void work()
{
    cin >> n;
    ans = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int len = 1; len <= n; len++)
    {
        for (int str = 0; str+len <= n; str++)
        {
            vector<int> temp(len);
            for (int nowPos = 0; nowPos < len; nowPos++)
            {
                temp[nowPos] = nums[str+nowPos];
            }
            ans += getValue(temp);
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