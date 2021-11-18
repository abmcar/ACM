class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // ��¼��������
        vector<int> totNum;
        // �����ܳ�
        int totLen = nums1.size() + nums2.size();
        // ������ϲ�
        int pos1, pos2;
        pos1 = pos2 = 0;
        while (pos1 < nums1.size() && pos2 < nums2.size())
        {
            // ��֤����
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
        // ���������С������λ��
        if (totLen % 2)
            return totNum[totLen / 2];
        else
            return (1.0 * totNum[totLen / 2 - 1] + totNum[totLen / 2]) / 2;
    }
};