class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        // 特判不存在解的情况
        if (nums.empty() || nums.size() <= 2)
            return -1;
        // 排序保证有序
        sort(nums.begin(), nums.end());
        // 当前最近接的答案
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            // 取范围[i+1,num.size()-1]
            int left = i + 1, right = nums.size() - 1;
            // 取下标为left,i,right的三个数和作为答案步步逼近
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                // 更新最接近答案
                if (abs(sum - target) < abs(res - target))
                    res = sum;
                // 若相等则直接返回,否则逐步调整逼近
                if (sum == target)
                    return target;
                else if (sum < target)
                    ++left;
                else if (sum > target)
                    --right;
            }
        }
        return res;
    }
};