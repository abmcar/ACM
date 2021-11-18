class Solution
{
public:
    int reverse(int x)
    {
        // ��¼��ת���
        long long ans = 0;
        // ��¼�Ƿ�Ϊ����
        bool flag = false;
        if (x < 0)
            flag = true;
        while (x)
        {
            ans = ans * 10LL;
            ans = ans + (long long)(x % 10);
            x = x / 10;
        }
        // ��������
        if (flag && ans > 0)
            ans = ans * -1LL;
        // �ж��Ƿ񳬹�2^31-1
        if (abs(ans) > (1LL << 31) - 1LL)
            return 0;
        return ans;
    }
};