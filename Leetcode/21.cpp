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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        
        ListNode* result;
        if (l1->val < l2->val) {
            result = l1;
            l1 = l1->next;
        } else {
            result = l2;
            l2 = l2->next;
        }
        ListNode* temp = result;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        while (l1 != NULL) {
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
        return result;
    }
};