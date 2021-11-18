#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ackerman(int m, int n)
{

    // 如果要求解A(m,n)，若n"很大"，且m较大时，第一个dp[0]的大小要开很大
    // 因为ackerman函数增长太快，以下模拟求解ackerman(m,n)的DP解法
    vector<vector<int>> dp(m + 1, vector<int>(1000000 + 1, 0));
    for (int j = 0; j < 1000000 + 1; j++)
    {
        dp[0][j] = j + 1;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 0; j < 1000000 + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][1];
            }
            else
            {
                if (dp[i][j - 1] > 1000000)
                    continue; // 超出
                dp[i][j] = dp[i - 1][dp[i][j - 1]];
            }
        }
    }
    return dp;
    // 从输出数列中看到A(4,1)已经很大了，A(4,2)已经难以用int表示，
    // 所需要的dp空间更是恐怖
    // 不过可以自己写高精度加法来实现
}

int main()
{
    auto ackermanDP = ackerman(4, 1);
    cout << ackermanDP[4][1] << endl;
    //system("pause");
    return 0;
}