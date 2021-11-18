class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // 表示当前能跳的最远距离
        int nowPos = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // 当前位置无法跳到,则最后一个位置必定无法跳到
            if (i > nowPos)
                return false;
            // 更新最远距离
            nowPos = max(nowPos, i + nums[i]);
        }
        // 此时能跳的最远位置大于数组长度
        return true;
    }
};