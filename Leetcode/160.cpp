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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* listA = headA;
        ListNode* listB = headB;
        while (listA != NULL) {
            lenA++;
            listA = listA->next;
        }
        while (listB != NULL) {
            lenB++;
            listB = listB->next;
        }
        listA = headA;
        listB = headB;
        while (lenA > lenB) {
            listA = listA->next;
            lenA--;
        }
        while (lenB > lenA) {
            listB = listB->next;
            lenB--;
        }
        while (listA != listB && lenA > 0) {
            lenA--;
            listA = listA->next;
            listB = listB->next;
        }
        if (listA != listB) return NULL;
        else return listA;
    }
};