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
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        queue<ListNode*> part1;
        stack<ListNode*> part2;
        ListNode* list = head;
        int len = 0;
        while (list != NULL) {
            len++;
            list = list->next;
        }
        list = head;
        int count = 0;
        while (list != NULL) {
            if (count <= len / 2) part1.push(list);
            else part2.push(list);
            count++;
            list = list->next;
        }
        part1.pop();
        list = head;
        bool flag = false;
        while (!part1.empty() || !part2.empty()) {
            if (flag && !part1.empty()) {
                list->next = part1.front();
                part1.pop();
                list = list->next;
                list->next = NULL;
            } else if (!part2.empty()) {
                list->next = part2.top();
                part2.pop();
                list = list->next;
                list->next = NULL;
            }
            flag = !flag;
        }
    }
};