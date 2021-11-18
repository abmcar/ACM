class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int i = 0;
        // 枚举未超出范围的点
        while (i < n)
        {
            int sumGas = 0, sumCost = 0;
            // 记录跑了多少个点
            int cnt = 0;
            // 当经过点数小于n时一直跑
            while (cnt < n)
            {
                // 计算下一个位置的下标
                int j = (i + cnt) % n;
                sumGas += gas[j];
                sumCost += cost[j];
                // 如果油不够跳出
                if (sumCost > sumGas)
                    break;
                cnt++;
            }
            // 如果跑够了n个点,则起点为答案
            if (cnt == n)
                return i;
            // 否则从刚才跑的最后一个点开始继续作为起点
            i = i + cnt + 1;
        }
        return -1;
    }
};
