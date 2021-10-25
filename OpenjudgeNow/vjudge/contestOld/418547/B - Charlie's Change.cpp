#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

const int Maxn = 10010;
int n;
int num[5];
int val[5] = {0, 1, 5, 10, 25};
int ans[30];
int dp[Maxn];
int pre[Maxn];
int cnt[Maxn];

int main()
{
    std::ios::sync_with_stdio(false);
    while (cin >> n)
    {
        for (int i = 1; i <= 4; i++)
            cin >> num[i];
        if (!n && !num[4] && !num[1] && !num[2] && !num[3])
            return 0;
        fill(dp, dp + Maxn, -1e8);
        fill(pre, pre + Maxn, 0);
        fill(ans, ans + 30, 0);
        dp[0] = 0;
        pre[0] = -1;
        for (int i = 1; i <= 4; i++)
        {
            memset(cnt, 0, sizeof(cnt));
            for (int j = val[i]; j <= n; j++)
                if (dp[j - val[i]] + 1 > dp[j] && cnt[j - val[i]] + 1 <= num[i])
                {
                    dp[j] = dp[j - val[i]] + 1;
                    cnt[j] = cnt[j - val[i]] + 1;
                    pre[j] = j - val[i];
                }
        }
        if(dp[n] < 0)
        {
            cout << "Charlie cannot buy coffee." << endl;
            continue;
        }
        int num = n;
        while(pre[num] != -1)
        {
            ans[num - pre[num]]++;
            num = pre[num];
        }
        printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",ans[1],ans[5],ans[10],ans[25]);
    }
    return 0;
}