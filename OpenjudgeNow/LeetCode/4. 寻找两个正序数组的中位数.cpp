class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // 记录所有数字
        vector<int> totNum;
        // 数组总长
        int totLen = nums1.size() + nums2.size();
        // 两数组合并
        int pos1, pos2;
        pos1 = pos2 = 0;
        while (pos1 < nums1.size() && pos2 < nums2.size())
        {
            // 保证有序
            if (nums1[pos1] <= nums2[pos2])
            {
                totNum.push_back(nums1[pos1]);
                pos1++;
            }
            else
            {
                totNum.push_back(nums2[pos2]);
                pos2++;
            }
        }
        while (pos1 < nums1.size())
            totNum.push_back(nums1[pos1++]);
        while (pos2 < nums2.size())
            totNum.push_back(nums2[pos2++]);
        // 根据数组大小返回中位数
        if (totLen % 2)
            return totNum[totLen / 2];
        else
            return (1.0 * totNum[totLen / 2 - 1] + totNum[totLen / 2]) / 2;
    }
};