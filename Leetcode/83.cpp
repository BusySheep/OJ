/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    void deleteNode(ListNode* pre, ListNode* node) {
        pre->next = node->next;
        delete node;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto node = head;
        while (node && node->next) {
            if (node->next->val == node->val) {
                deleteNode(node, node->next);
            } else {
                node = node->next;
            }
        }
        return head;
    }
};