class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        // �Ӵ�Сö��ÿһ�������жϻ���
        for (int i = len; i >= 0; i--)
        {
            // ö���ַ����г���Ϊi��ÿһ��Ƭ��
            for (int j = 0; j <= len - i; j++)
            {
                // ����flag��ʾ��ǰƬ���Ƿ�Ϊ�����Ӵ�
                bool flag = true;
                for (int k = 0; k < (i + 1) / 2; k++)
                    // �ж��Ӵ��ĵ�k���͵�����k���ַ��Ƿ����
                    if (s[j + k] != s[j + i - k - 1])
                    {
                        // ���ǻ��Ĵ�,����ѭ��
                        flag = false;
                        break;
                    }
                if (flag)
                    // ʹ��string��substrȡ��j��ʼ�ĳ���Ϊi���Ӵ�
                    return s.substr(j, i);
            }
        }
        return "";
    }
};