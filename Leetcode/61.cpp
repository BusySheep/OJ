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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == 0) return head;
        int len = 0;
        auto node = head;
        while (node) {
            node = node->next;
            len++;
        }
        k %= len;
        if (k == 0) return head;
        auto prePoint = head;
        for (int i = 0; i < k; i++) {
            prePoint = prePoint->next;
        }
        auto point = head;
        while (prePoint->next) {
            point = point->next;
            prePoint = prePoint->next;
        }
        auto newHead = point->next;
        point->next = nullptr;
        prePoint->next = head;
        return newHead;
    }
};