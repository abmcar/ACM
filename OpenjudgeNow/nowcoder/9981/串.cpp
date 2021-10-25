#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#define Maxn (int)1e6 + 10
#define ll long long
using namespace std;

const ll Mod = 1e9+7;
ll n;
ll dp[Maxn][3];
ll ans;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i-1][0] * 25 % Mod;
        dp[i][1] = (dp[i-1][1] * 25 % Mod + dp[i-1][0]) % Mod;
        dp[i][2] = (dp[i-1][1] + dp[i-1][2] * 26 % Mod) % Mod;
    }
    for(int i = 1; i <= n; i++)
        ans = (ans + dp[i][2]) % Mod;
    cout << ans;
    return 0;
}
/*

ans[i] = (26*ans[i-1])+(26^(i-1)-25^(i-1)-ans[i-1])
       = 25*ans[i-1]+26^(i-1)-25^(i-1);

*/