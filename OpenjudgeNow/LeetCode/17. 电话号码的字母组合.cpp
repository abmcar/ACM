class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        // Ԥ�������ͬ���ְ����������ĸ
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
        // ������ĸ
        for (int i = 0; i < digits.size(); i++)
        {
            // ��ȡ��ǰ�����е��ַ�������Ŀ
            int nowLen = nowString.size();
            // ö�ٲ�ͬ��ĸ
            for (int j = 0; j < board[digits[i]].size(); j++)
            {
                // ö���ַ���,���ַ����Ĵ�СΪi,������Ч����,���Լ�������
                for (int k = 0; k < nowLen; k++)
                {
                    if (nowString[k].size() == i)
                        nowString.push_back(nowString[k] + board[digits[i]][j]);
                }
            }
        }
        // �����ӳ��ȷ���Ҫ����ַ���
        for (int i = 0; i < nowString.size(); i++)
            if (nowString[i].size() == digits.size())
                ans.push_back(nowString[i]);
        return ans;
    }
};