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

int n, m;
int nums[Maxn], d[Maxn];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        d[t1]++;
        d[t2 + 1]--;
    }
    int cntNum = 0;
    for (int i = 1; i <= n; i++)
    {
        cntNum += d[i];
        nums[i] = cntNum;
    }
    sort(nums + 1, nums + 1 + n);
    cout << nums[(n + 1) / 2] << endl;
    return 0;
}