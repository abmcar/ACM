class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        // ���в����ڽ�����
        if (nums.empty() || nums.size() <= 2)
            return -1;
        // ����֤����
        sort(nums.begin(), nums.end());
        // ��ǰ����ӵĴ�
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            // ȡ��Χ[i+1,num.size()-1]
            int left = i + 1, right = nums.size() - 1;
            // ȡ�±�Ϊleft,i,right������������Ϊ�𰸲����ƽ�
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                // ������ӽ���
                if (abs(sum - target) < abs(res - target))
                    res = sum;
                // �������ֱ�ӷ���,�����𲽵����ƽ�
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