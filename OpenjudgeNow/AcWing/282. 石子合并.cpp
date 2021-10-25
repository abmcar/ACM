#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define Buff std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define inf LONG_LONG_MAX
#define Inf INT_MAX
#define endl "\n"
#define Endl "\n"
// #define Debug

using namespace std;

const int Maxn = 1e3 + 10;
const ll Mod = 1e9 + 7;

int n;
ll w[Maxn], dp[Maxn][Maxn];
int preAns[Maxn];

int main()
{
    Buff;
#ifdef Debug
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i], preAns[i] = preAns[i - 1] + w[i];
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i + l - 1 <= n; i++)
        {
            int j = i + l - 1;
            dp[i][j] = Inf;
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + preAns[j] - preAns[i - 1]);
            // cout << i << " " << j << " ";
            // cout << dp[i][j] << endl;
        }
    }
    cout << dp[1][n] << Endl;
    return 0;
}