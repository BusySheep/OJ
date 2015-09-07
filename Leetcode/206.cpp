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
    ListNode* iterativelyReverse(ListNode* head) {
        if (head == NULL) return NULL;
        stack<ListNode*> s;
        while (head != NULL) {
            s.push(head);
            head = head->next;
        }
        ListNode* result = s.top();
        s.pop();
        result->next = NULL;
        ListNode* list = result;
        while (!s.empty()) {
            list->next = s.top();
            s.pop();
            list = list->next;
            list->next = NULL;
        }
        return result;
    }
    pair<ListNode*, ListNode*> doRecursivelyReverse(ListNode* head) {
        if (head->next == NULL) return make_pair(head, head);
        auto reversed = doRecursivelyReverse(head->next);
        reversed.second->next = head;
        head->next = NULL;
        return make_pair(reversed.first, head);
    }
    ListNode* recursivelyReverse(ListNode* head) {
        if (head == NULL) return NULL;
        else return doRecursivelyReverse(head).first;
    }
public:
    ListNode* reverseList(ListNode* head) {
        // return iterativelyReverse(head);
        return recursivelyReverse(head);
    }
};