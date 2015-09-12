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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* beforeSlow = NULL;
        while (n--) {
            fast = fast->next;
        }
        while (fast) {
            beforeSlow = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (beforeSlow == NULL) {
            auto newHead = head->next;
            delete head;
            return newHead;
        } else {
            beforeSlow->next = slow->next;
            delete slow;
            return head;
        }
    }
};