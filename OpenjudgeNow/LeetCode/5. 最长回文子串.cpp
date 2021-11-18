class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        // 从大到小枚举每一个长度判断回文
        for (int i = len; i >= 0; i--)
        {
            // 枚举字符串中长度为i的每一个片段
            for (int j = 0; j <= len - i; j++)
            {
                // 定义flag表示当前片段是否为回文子串
                bool flag = true;
                for (int k = 0; k < (i + 1) / 2; k++)
                    // 判断子串的第k个和倒数第k个字符是否相等
                    if (s[j + k] != s[j + i - k - 1])
                    {
                        // 不是回文串,跳出循环
                        flag = false;
                        break;
                    }
                if (flag)
                    // 使用string的substr取从j开始的长度为i的子串
                    return s.substr(j, i);
            }
        }
        return "";
    }
};