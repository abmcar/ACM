class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        // 预处理出不同数字按键代表的字母
        map<char, string> board;
        board['2'] = "abc";
        board['3'] = "def";
        board['4'] = "ghi";
        board['5'] = "jkl";
        board['6'] = "mno";
        board['7'] = "pqrs";
        board['8'] = "tuv";
        board['9'] = "wxyz";
        if (digits.size() == 0)
            return ans;
        vector<string> nowString;
        nowString.push_back("");
        // 增添字母
        for (int i = 0; i < digits.size(); i++)
        {
            // 获取当前构造中的字符串的数目
            int nowLen = nowString.size();
            // 枚举不同字母
            for (int j = 0; j < board[digits[i]].size(); j++)
            {
                // 枚举字符串,若字符串的大小为i,则是有效构造,可以继续构造
                for (int k = 0; k < nowLen; k++)
                {
                    if (nowString[k].size() == i)
                        nowString.push_back(nowString[k] + board[digits[i]][j]);
                }
            }
        }
        // 向答案添加长度符合要求的字符串
        for (int i = 0; i < nowString.size(); i++)
            if (nowString[i].size() == digits.size())
                ans.push_back(nowString[i]);
        return ans;
    }
};