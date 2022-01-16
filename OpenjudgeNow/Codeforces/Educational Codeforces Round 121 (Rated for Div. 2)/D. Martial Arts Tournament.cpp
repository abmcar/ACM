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
vector<int> nums;

void work()
{
    cin >> n;
    vector<int> na(n+1);
    for (int i = 1; i <= n; i++)
        cin >> na[i];
}

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int cnt = 1;
    while (cnt <= 1e5)
    {
        nums.push_back(cnt);
        cnt *= 2;
    }
    cin >> t;
    while (t--)
        work();
    return 0;
}