/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    // ��ȡ��ǰlists����С��value
    int getMinNum(vector<ListNode *> &lists)
    {
        int minValue = 99999;
        int minPos = -1;
        // ö��lists�е�ÿһ��
        for (int i = 0; i < lists.size(); i++)
        {
            // �����ǰ�ڵ��ѿ�������
            if (lists[i] == nullptr)
                continue;
            // �����ǰ�ڵ��valueС��֮ǰ��minValue,���¼����
            if (lists[i]->val < minValue)
            {
                minValue = lists[i]->val;
                minPos = i;
            }
        }
        // ����ȡ����Сֵ�������С������
        if (minPos != -1)
            lists[minPos] = lists[minPos]->next;
        return minValue;
    }

    // ����ֵ
    void insert(ListNode *strNode, int value)
    {
        ListNode *preNode = strNode;
        ListNode *nowNode = strNode->next;
        // ������β
        while (nowNode != nullptr)
        {
            preNode = nowNode;
            nowNode = preNode->next;
        }
        // ������β�����½ڵ�
        nowNode = new ListNode(value);
        preNode->next = nowNode;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *strNode = new ListNode();
        strNode->val = getMinNum(lists);
        // �������Чֵ,�򷵻�nullptr
        if (strNode->val == 99999)
            return nullptr;
        // ����һֱȡ��Сֵ���뵽������,ֱ��ȡ��
        int nextNum = getMinNum(lists);
        while (nextNum != 99999)
        {
            insert(strNode, nextNum);
            nextNum = getMinNum(lists);
        }
        return strNode;
    }
};