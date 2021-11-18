class Solution
{
public:
    // ���ַ��Ƿ�ƥ��
    bool matches(string s, string p, int i, int j)
    {
        // ��ͷ����
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

        // dp[i][j]��ʾs��ǰi���ַ���p�е�ǰj���ַ��Ƿ��ܹ�ƥ��
        bool dp[50][50];
        memset(dp, false, sizeof dp);
        dp[0][0] = true;

        for (int i = 0; i <= len1; ++i)
            for (int j = 1; j <= len2; ++j)
            {
                // �Ƿ��ܹ���ƥ��
                if (p[j - 1] == '*')
                {
                    // �̳�*֮ǰ��״̬
                    dp[i][j] |= dp[i][j - 2];
                    // ����ϸ����ַ�ƥ����̳�
                    if (matches(s, p, i, j - 1))
                        dp[i][j] |= dp[i - 1][j];
                }
                else
                {
                    // �����һλƥ����̳�
                    if (matches(s, p, i, j))
                        dp[i][j] |= dp[i - 1][j - 1];
                }
            }
        return dp[len1][len2];
    }
};