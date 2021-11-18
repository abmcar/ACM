class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // ��ʾ��ǰ��������Զ����
        int nowPos = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // ��ǰλ���޷�����,�����һ��λ�ñض��޷�����
            if (i > nowPos)
                return false;
            // ������Զ����
            nowPos = max(nowPos, i + nums[i]);
        }
        // ��ʱ��������Զλ�ô������鳤��
        return true;
    }
};