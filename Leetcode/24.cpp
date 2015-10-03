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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        head = second;
        first->next = second->next;
        second->next = first;
        ListNode* pre = first;
        while (first->next && first->next->next) {
            first = first->next;
            second = first->next;
            pre->next = second;
            first->next = second->next;
            second->next = first;
            pre = first;
        }
        return head;
    }
};