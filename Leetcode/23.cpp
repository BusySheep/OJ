/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class comparator {
public:
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val < b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        multiset<ListNode*, comparator> remainLists;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                remainLists.insert(lists[i]);
            }
        }
        if (remainLists.empty()) {
            return NULL;
        }
        auto tempIt = remainLists.begin();
        result = *tempIt;
        remainLists.erase(tempIt);
        if (result->next != NULL) {
            remainLists.insert(result->next);
        }
        ListNode* temp = result;
        while (!remainLists.empty()) {
            auto tempIt = remainLists.begin();
            ListNode* minNode = *tempIt;
            temp->next = minNode;
            temp = temp->next;
            remainLists.erase(tempIt);
            if (minNode->next != NULL) {
                remainLists.insert(minNode->next);
            }
        }
        return result;
    }
};