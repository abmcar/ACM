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

int n;
vector<int> leastInser;

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    leastInser.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int t[4];
        for (int j = 1; j <= 3; j++)
        {
            cin >> t[j];
            if (t[j])
                leastInser[i - j] = max(leastInser[i - j], 3 - j + 1);
        }
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        if (!leastInser[i])
            continue;
        if (leastInser[i] == 3)
            ans += leastInser[i];
        else
        {
            if (leastInser[i] == 1)
            {
                if (leastInser[i + 1] || leastInser[i + 2])
                {
                    leastInser[i] = 0;
                    continue;
                }
                else
                    ans++;
            }
            if (leastInser[i] == 2)
            {
                if (leastInser[i + 1] == 3 || leastInser[i + 1] == 2)
                {
                    leastInser[i] = 0;
                    continue;
                }
                if (leastInser[i + 1] == 1)
                {
                    leastInser[i] = 1;
                    ans++;
                    continue;
                }
                ans += 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}