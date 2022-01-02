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

int t, n;

void work()
{
    cin >> n;
    map<int,int> M;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        M[temp]++;
    }
    for (auto it : M)
    {
        // cout << it.first << " " << it.second << endl;
        // if (it.second == 0)
        //     continue;
        if (it.second >= 2 && M[it.first * -1] == 0)
            ans += 2;
        else
            ans++;
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