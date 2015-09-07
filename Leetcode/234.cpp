#include <vector>
#include <algorithm>
#include <iostream>
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
    ListNode* reverseList(ListNode* head) {
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
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        auto first = head;
        auto second = reverseList(slow);
        while (first && second) {
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        reverseList(second); // recover the list
        return true;
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
    vector<int> input = {-31900,22571,-31634,19735,13748,16612,-28299,-16628,9614,-14444,-14444,9614,-16628,-31900,16612,13748,19735,-31634,22571,-28299};
    ListNode* head = genList(input);
    Solution().isPalindrome(head);
    return 0;
}

