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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 0;
        stack<ListNode*> s;
        auto list = head;
        ListNode* beforeReverse = NULL;
        ListNode* afterReverse = NULL;
        while (list != NULL) {
            count++;
            if (count == m - 1) beforeReverse = list;
            else if (count >= m && count <= n) s.push(list); 
            else if (count == n + 1) {
                afterReverse = list;
                auto reverseHead = s.top();
                s.pop();
                if (beforeReverse != NULL) beforeReverse->next = reverseHead;
                else head = reverseHead;
                reverseHead->next = afterReverse;
                auto reverseList = reverseHead;
                while (!s.empty()) {
                    reverseList->next = s.top();
                    s.pop();
                    reverseList = reverseList->next;
                    reverseList->next = afterReverse;
                }
            }
            list = list->next;
        }
        if (count < n + 1) {
            afterReverse = list;
            auto reverseHead = s.top();
            s.pop();
            if (beforeReverse != NULL) beforeReverse->next = reverseHead;
            else head = reverseHead;
            reverseHead->next = afterReverse;
            auto reverseList = reverseHead;
            while (!s.empty()) {
                reverseList->next = s.top();
                s.pop();
                reverseList = reverseList->next;
                reverseList->next = afterReverse;
            }
        }
        return head;
    }
};