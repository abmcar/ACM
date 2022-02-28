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

const int Maxn = 3e5 + 10;
const ll Mod = 1e9 + 7;

int t, n, m;

unordered_map<int, int> M[Maxn];

void work()
{
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    for (int i = 0; i <= 2 * n; i++)
        M[i].clear();
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= 2 * n - 1; j++)
        {
            for (auto it : M[j - i])
            {
                M[j][it.first + 1] = max(M[j][it.first + 1], it.second + nums[i]);
            }
        }
    }
    cout << M[2 * n - 1][n] << endl;
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

// 1
// 10
// 2 6 3 9 5 10 15 20 15 15