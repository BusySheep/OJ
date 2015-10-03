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
    ListNode* reverseList(ListNode* reverseBegin, ListNode* reverseEnd, ListNode* next) {
        auto node = reverseBegin;
        auto pre = next;
        while (node != next) {
            auto temp = node->next;
            node->next = pre;
            pre = node;
            node = temp;
        }
        return reverseEnd;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;
        int count = 0;
        auto node = head;
        auto reverseBegin = node;
        auto pre = new ListNode(0);
        pre->next = head;
        head = pre;
        while (node) {
            count++;
            if (count == k) {
                auto temp = node->next;
                pre->next = reverseList(reverseBegin, node, node->next);
                pre = reverseBegin;
                reverseBegin = temp;
                count = 0;
                node = temp;
            } else {
                node = node->next;
            }
        }
        auto temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};