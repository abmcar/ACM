class Solution
{
public:
    // 单字符是否匹配
    bool matches(string s, string p, int i, int j)
    {
        // 开头特判
        if (i == 0)
            return false;
        if (p[j - 1] == '.')
            return true;
        return s[i - 1] == p[j - 1];
    };

    bool isMatch(string s, string p)
    {
        int len1 = s.size();
        int len2 = p.size();

        // dp[i][j]表示s的前i个字符与p中的前j个字符是否能够匹配
        bool dp[50][50];
        memset(dp, false, sizeof dp);
        dp[0][0] = true;

        for (int i = 0; i <= len1; ++i)
            for (int j = 1; j <= len2; ++j)
            {
                // 是否能够多匹配
                if (p[j - 1] == '*')
                {
                    // 继承*之前的状态
                    dp[i][j] |= dp[i][j - 2];
                    // 如果上个单字符匹配则继承
                    if (matches(s, p, i, j - 1))
                        dp[i][j] |= dp[i - 1][j];
                }
                else
                {
                    // 如果上一位匹配则继承
                    if (matches(s, p, i, j))
                        dp[i][j] |= dp[i - 1][j - 1];
                }
            }
        return dp[len1][len2];
    }
};