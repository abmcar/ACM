#include <bits/stdc++.h>
using namespace std;

int const Maxn = 1e3 + 5;
int dp[Maxn*1000];

int ackerman(int m, int n)
{
    for (int j = 0; j <= 1e6; j++)
        dp[j] = j + 1;
    for (int i = 1; i <= m+1; i++)
    {
        for (int j = 1e6; j >= 0; j--)
        {
            if (j == 0)
                dp[j] = dp[1];
            else
            {
                if (dp[j - 1] > 1e6)
                    continue;
                dp[j] = dp[dp[j - 1]];
            }
        }
    }
    return dp[n];
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << ackerman(m, n) << endl;
    return 0;
}