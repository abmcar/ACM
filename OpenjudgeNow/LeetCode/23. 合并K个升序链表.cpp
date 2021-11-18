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
    // 获取当前lists中最小的value
    int getMinNum(vector<ListNode *> &lists)
    {
        int minValue = 99999;
        int minPos = -1;
        // 枚举lists中的每一个
        for (int i = 0; i < lists.size(); i++)
        {
            // 如果当前节点已空则跳过
            if (lists[i] == nullptr)
                continue;
            // 如果当前节点的value小于之前的minValue,则记录下来
            if (lists[i]->val < minValue)
            {
                minValue = lists[i]->val;
                minPos = i;
            }
        }
        // 若能取到最小值则更新最小的链表
        if (minPos != -1)
            lists[minPos] = lists[minPos]->next;
        return minValue;
    }

    // 插入值
    void insert(ListNode *strNode, int value)
    {
        ListNode *preNode = strNode;
        ListNode *nowNode = strNode->next;
        // 到链表尾
        while (nowNode != nullptr)
        {
            preNode = nowNode;
            nowNode = preNode->next;
        }
        // 在链表尾插入新节点
        nowNode = new ListNode(value);
        preNode->next = nowNode;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *strNode = new ListNode();
        strNode->val = getMinNum(lists);
        // 如果无有效值,则返回nullptr
        if (strNode->val == 99999)
            return nullptr;
        // 否则一直取最小值插入到新链表,直到取完
        int nextNum = getMinNum(lists);
        while (nextNum != 99999)
        {
            insert(strNode, nextNum);
            nextNum = getMinNum(lists);
        }
        return strNode;
    }
};