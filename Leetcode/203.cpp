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
    ListNode* removeElements(ListNode* head, int val) {
        auto list = new ListNode(0);
        list->next = head;
        head = list;
        while (list->next) {
            if (list->next->val == val) {
                auto temp = list->next;
                list->next = list->next->next;
                delete temp;
            } else {
                list = list->next;
            }
        }
        list = head;
        head = head->next;
        delete list;
        return head;
    }
};