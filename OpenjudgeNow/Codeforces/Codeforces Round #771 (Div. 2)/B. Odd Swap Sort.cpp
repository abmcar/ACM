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
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    vector<int> n1, n2;
    for (int i = 1; i <= n; i++)
    {
        if (nums[i] % 2)
            n1.push_back(nums[i]);
        else
            n2.push_back(nums[i]);
    }
    // cout << n1.size() << " " << n2.size() << Endl;
    for (int i = 0; i < int(n1.size() - 1); i++)
    {
        if (n1[i] > n1[i + 1])
        {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = 0; i < int(n2.size() - 1); i++)
        if (n2[i] > n2[i + 1])
        {
            cout << "No" << endl;
            return;
        }
    cout << "Yes" << endl;
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