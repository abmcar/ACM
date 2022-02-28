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
    vector<int> ans;
    bool fir = true;
    for (int i = 1; i <= n; i++)
    {
        if (fir)
        if (i != nums[i])
        {
            fir = false;
            stack<int> s;
            for (int j = i; j <= n; j++)
            {
                s.push(nums[j]);
                if (nums[j] == i)
                {
                    for (int k = i; k <= j; k++)
                    {
                        nums[k] = s.top();
                        s.pop();
                    }
                    break;
                }
            }
        }
        cout << nums[i] << " ";
    }
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