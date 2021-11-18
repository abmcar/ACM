class Solution
{
public:
    int reverse(int x)
    {
        // 记录翻转结果
        long long ans = 0;
        // 记录是否为负数
        bool flag = false;
        if (x < 0)
            flag = true;
        while (x)
        {
            ans = ans * 10LL;
            ans = ans + (long long)(x % 10);
            x = x / 10;
        }
        // 负数修正
        if (flag && ans > 0)
            ans = ans * -1LL;
        // 判断是否超过2^31-1
        if (abs(ans) > (1LL << 31) - 1LL)
            return 0;
        return ans;
    }
};