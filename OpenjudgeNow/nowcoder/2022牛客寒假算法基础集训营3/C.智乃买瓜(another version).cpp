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

const int Maxn = 1e3;
const ll Mod = 1e9 + 7;

int m;
int f[Maxn+10][Maxn * 3];

signed main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> m;
    vector<int> nums(m + 1), ans;
    for (int i = 1; i <= m; i++)
        cin >> nums[i];
    int cnt = 1;
    f[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = f[cnt - 1][i]; j < nums[i]; j++)
        {
            for (int k = 0; k <= m; k++)
            {
                f[cnt][k] = (f[cnt][k] + f[cnt - 1][k]) % Mod;
                f[cnt][k + i] = (f[cnt][k + i] + f[cnt - 1][k]) % Mod;
                f[cnt][k + i * 2] = (f[cnt][k + i * 2] + f[cnt - 1][k]) % Mod;
            }
            cnt++;
            ans.push_back(i * 2);
        }
    }
    cout << ans.size() << endl;
    for (int it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}