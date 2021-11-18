class Solution
{
public:
    // ��
    vector<vector<int>> ans;
    // �ж��Ƿ��ȡ
    bool vis[1234];

    // dfs�����������
    void dfs(int nowDeep, vector<int> nowAns, vector<int> nums)
    {
        // ���ȡ������Ӵ�
        if (nowDeep == nums.size())
        {
            ans.push_back(nowAns);
            return;
        }
        // ö��ÿһ���ж��Ƿ��ȡ
        for (int i = 0; i < nums.size(); i++)
            if (vis[i] == 0)
            {
                vis[i] = true;
                // �����µĴ�
                vector<int> nextVector = nowAns;
                nextVector.push_back(nums[i]);
                dfs(nowDeep + 1, nextVector, nums);
                // ȡ�����ʹ���´ο���ʹ��
                vis[i] = false;
            }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        dfs(0, vector<int>(), nums);
        return ans;
    }
};