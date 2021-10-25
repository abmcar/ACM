/*
 * @Author: hesorchen
 * @Date: 2020-12-30 15:48:28
 * @LastEditTime: 2021-03-29 23:30:44
 * @Description: 鏍界?嶇粷澶勭殑鑺?;
 */
#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long n, k;

long long dp[1010][1010][2];

long long dfs(long long pos, long long now, long long fx)
{
    // cout << pos << ' ' << now << ' ' << fx << endl;
    long long res = 1;
    if (now == 1)
        return res;
    if (dp[pos][now][fx])
        return dp[pos][now][fx];
    if (fx == 1)
    {
        for (int i = pos + 1; i <= n; i++)
        {
            res = (res + dfs(i, now - 1, 0)) % mod;
        }
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            res = (res + dfs(i, now - 1, 1)) % mod;
        }
    }
    dp[pos][now][fx] = res;
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= k + 1; j++)
                dp[i][j][0] = dp[i][j][1] = 0;
        cout << dfs(0, k, 1) << endl;
    }

    return 0;
}

/*


*/