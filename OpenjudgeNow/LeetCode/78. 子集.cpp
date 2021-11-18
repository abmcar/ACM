class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        // 二进制子集生成,对于集合i,判断二进制的第j位是0还是1来生成子集
        for (int i = 0; i < (1 << nums.size()); i++)
        {
            // 当前集合
            vector<int> nowSet;
            // 判断第j个数是否取
            for (int j = 0; j < nums.size(); j++)
                if (i & (1 << j))
                    // 压入集合
                    nowSet.push_back(nums[j]);
            // 子集生成完毕,加入答案
            ans.push_back(nowSet);
        }
        return ans;
    }
};