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
    cin >> n >> m;
    vector<int> nums(n + 1), preAns(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i]; 
    for (int i = 1; i <= n; i++)
        preAns[i] = preAns[i - 1] + nums[i];
    vector<int> M(n + 1, -1e18);
    vector<pair<int, int>> allSem;
    for (int len = 1; len <= n; len++)
    {
        for (int str = 1; str + len - 1 <= n; str++)
        {
            M[len] = max(M[len], preAns[str + len - 1] - preAns[str - 1]);
        }
        allSem.push_back({M[len], len});
    }
    sort(allSem.begin(), allSem.end(), greater<pair<int, int>>());
    // cout << preAns[n] << " ";
    for (int len = 0; len <= n; len++)
    {
        int nowAns = 0;
        for (auto it : allSem)
            nowAns = max(nowAns, it.first + m * min(len, it.second));
        cout << nowAns << " \n"[len == n];
    }
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