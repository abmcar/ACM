class Solution
{
public:
    string convert(string s, int numRows)
    {
        // 行数为1则不需要进行更改
        if (numRows == 1)
            return s;
        // 记录不同行的字符
        string rows[1234];
        // 当前行
        int curRow = 0;
        // 是否正在向下
        bool nowDown = false;

        for (char c : s)
        {
            rows[curRow] += c;
            // 最上和最下特判更改方向
            if (curRow == 0 || curRow == numRows - 1)
                nowDown = !nowDown;
            // 根据方向更改当前行
            if (nowDown)
                curRow++;
            else
                curRow--;
        }
        // 统计答案
        string ret;
        for (int i = 0; i < numRows; i++)
            ret = ret + rows[i];
        return ret;
    }
};
