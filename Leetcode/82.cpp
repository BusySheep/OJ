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
    void deleteNode(ListNode* pre, ListNode* &node) {
        if (pre) pre->next = node->next;
        auto temp = node;
        node = node->next;
        delete temp;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        auto node = head;
        ListNode* pre = nullptr;
        bool removeFlag = false;
        bool headIsStable = false;
        while (node) {
            if (node->next && node->next->val == node->val) {
                removeFlag = true;
                deleteNode(pre, node);
            } else {
                if (removeFlag) {
                    removeFlag = false;
                    deleteNode(pre, node);
                    if (!headIsStable) {
                        head = node;
                    }
                } else {
                    pre = node;
                    node = node->next;
                    if (!headIsStable) {
                        headIsStable = true;
                    }
                }
            }
        }
        if (!headIsStable) return nullptr;
        else return head;
    }
};