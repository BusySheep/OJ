/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* t = result;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int temp = l1->val;
            temp += l2->val + carry;
            carry = temp / 10;
            temp %= 10;
            t->next = new ListNode(temp);
            t = t->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            t->next = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            t = t->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            t->next = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            t = t->next;
            l2 = l2->next;
        }
        if (carry > 0) {
            t->next = new ListNode(carry);
        }
        t = result;
        result = result->next;
        delete t;
        return result;
    }
};