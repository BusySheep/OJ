#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    void print() {
        ListNode* temp = this;
        while (temp != NULL) {
            cout << temp->val << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
};

class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        
        ListNode* result;
        if (l1->val < l2->val) {
            result = l1;
            l1 = l1->next;
        } else {
            result = l2;
            l2 = l2->next;
        }
        ListNode* temp = result;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        while (l1 != NULL) {
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
        return result;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* head2 = head;
        ListNode* temp = head;
        ListNode* tail1 = head;
        while (temp != NULL && temp->next != NULL) {
            tail1 = head2;
            head2 = head2->next;
            temp = temp->next->next;
        }
        tail1->next = NULL;
        head = sortList(head);
        head2 = sortList(head2);
        return mergeTwoLists(head, head2);
    }
};

int main() {
    int n;
    cin >> n;
    ListNode* head = NULL;
    if (n > 0) {
        head = new ListNode(0);
        cin >> head->val;
        n--;
        ListNode* temp = head;
        while (n--) {
            temp->next = new ListNode(0);
            cin >> temp->next->val;
            temp = temp->next;
        }
    }
    head = Solution().sortList(head);
    head->print();
    return 0;
}