class Solution
{
public:
    string convert(string s, int numRows)
    {
        // ����Ϊ1����Ҫ���и���
        if (numRows == 1)
            return s;
        // ��¼��ͬ�е��ַ�
        string rows[1234];
        // ��ǰ��
        int curRow = 0;
        // �Ƿ���������
        bool nowDown = false;

        for (char c : s)
        {
            rows[curRow] += c;
            // ���Ϻ��������и��ķ���
            if (curRow == 0 || curRow == numRows - 1)
                nowDown = !nowDown;
            // ���ݷ�����ĵ�ǰ��
            if (nowDown)
                curRow++;
            else
                curRow--;
        }
        // ͳ�ƴ�
        string ret;
        for (int i = 0; i < numRows; i++)
            ret = ret + rows[i];
        return ret;
    }
};
