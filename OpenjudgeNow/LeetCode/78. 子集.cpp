class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        // �������Ӽ�����,���ڼ���i,�ж϶����Ƶĵ�jλ��0����1�������Ӽ�
        for (int i = 0; i < (1 << nums.size()); i++)
        {
            // ��ǰ����
            vector<int> nowSet;
            // �жϵ�j�����Ƿ�ȡ
            for (int j = 0; j < nums.size(); j++)
                if (i & (1 << j))
                    // ѹ�뼯��
                    nowSet.push_back(nums[j]);
            // �Ӽ��������,�����
            ans.push_back(nowSet);
        }
        return ans;
    }
};