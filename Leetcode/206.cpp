#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
        auto list = head;
        head = NULL;
        while (list) {
            auto next = list->next;
            list->next = head;
            head = list;
            list = next;
        }
        return head;
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
        return iterativelyReverse(head);
        // return recursivelyReverse(head);
    }
};

ListNode* genList(vector<int> input) {
    if (input.size() == 0) return NULL;
    ListNode* head = new ListNode(input[0]);
    auto list = head;
    for (int i = 1; i < input.size(); i++) {
        list->next = new ListNode(input[i]);
        list = list->next;
    }
    return head;
}

int main() {
    vector<int> input = {1, 2};
    auto head = genList(input);
    Solution().reverseList(head);
    return 0;
}