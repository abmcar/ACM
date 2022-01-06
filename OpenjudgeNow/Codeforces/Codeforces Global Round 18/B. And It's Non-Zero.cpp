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

int t;
int preAns[30][300000];
int nums[30][300000];

void pre()
{
    for (int i = 1; i <= 2e5; i++)
    {
        for (int j = 0; (1 << j) <= i; j++)
        {
            if ((1 << j) & i)
                nums[j][i]++;
        }
    }
    for (int i = 1; i <= 2e5; i++)
    {
        for (int j = 0; j <= 25; j++)
            preAns[j][i] = preAns[j][i - 1] + nums[j][i];
    }
}

void work()
{
    int l, r;
    int ans = 0;
    cin >> l >> r;
    for (int i = 0; i <= 25; i++)
        ans = max(preAns[i][r] - preAns[i][l - 1], ans);
    cout << (r-l+1)-ans << endl;
}

signed main()
{
    // cout << (1 << 2) << endl;
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    pre();
    cin >> t;
    while (t--)
        work();
    return 0;
}