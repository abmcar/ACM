/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* nextNode = head->next;
        ListNode* nowNode = head;
        ListNode* preNode = NULL;
        while (nextNode != NULL)
        {
            nowNode->next = preNode;
            nowNode = nextNode;
            preNode = nowNode;
            nextNode = nowNode->next;
        }
        nowNode->next = preNode;
        return nowNode;
    }
};