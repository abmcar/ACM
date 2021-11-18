class Solution
{
public:
    // 答案
    vector<vector<int>> ans;
    // 判断是否可取
    bool vis[1234];

    // dfs搜索所有情况
    void dfs(int nowDeep, vector<int> nowAns, vector<int> nums)
    {
        // 如果取完则添加答案
        if (nowDeep == nums.size())
        {
            ans.push_back(nowAns);
            return;
        }
        // 枚举每一个判断是否可取
        for (int i = 0; i < nums.size(); i++)
            if (vis[i] == 0)
            {
                vis[i] = true;
                // 构造新的答案
                vector<int> nextVector = nowAns;
                nextVector.push_back(nums[i]);
                dfs(nowDeep + 1, nextVector, nums);
                // 取消标记使得下次可以使用
                vis[i] = false;
            }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        dfs(0, vector<int>(), nums);
        return ans;
    }
};