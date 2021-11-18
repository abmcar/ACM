class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int i = 0;
        // ö��δ������Χ�ĵ�
        while (i < n)
        {
            int sumGas = 0, sumCost = 0;
            // ��¼���˶��ٸ���
            int cnt = 0;
            // ����������С��nʱһֱ��
            while (cnt < n)
            {
                // ������һ��λ�õ��±�
                int j = (i + cnt) % n;
                sumGas += gas[j];
                sumCost += cost[j];
                // ����Ͳ�������
                if (sumCost > sumGas)
                    break;
                cnt++;
            }
            // ����ܹ���n����,�����Ϊ��
            if (cnt == n)
                return i;
            // ����Ӹղ��ܵ����һ���㿪ʼ������Ϊ���
            i = i + cnt + 1;
        }
        return -1;
    }
};
