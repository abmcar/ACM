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
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    map<int, vector<int>> M;
    for (int i = 1; i <= n; i++)
        M[nums[i]].push_back(i);
    int ans = 0;
    for (auto it : M)
    {
        for (int j = 0; j + 1 < it.second.size(); j++)
        {
            int nowPos = it.second[j] + 1;
            int nextPos = it.second[j + 1] + 1;
            ans = max(ans, min(nowPos, nextPos) + min(n - nowPos, n - nextPos));
        }
    }
    if (ans == 0)
        ans = -1;
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