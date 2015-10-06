/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        auto node = root;
        TreeLinkNode* pre = nullptr;
        TreeLinkNode* nextHead = nullptr;
        while (node) {
            TreeLinkNode* firstChild = nullptr;
            TreeLinkNode* lastChild = nullptr;
            if (node->left && node->right) {
                node->left->next = node->right;
                firstChild = node->left;
                lastChild = node->right;
            } else if (node->left) {
                firstChild = lastChild = node->left;
            } else if (node->right) {
                firstChild = lastChild = node->right;
            }
            if (firstChild) {
                if (!nextHead) nextHead = firstChild;
                if (pre) pre->next = firstChild;
                pre = lastChild;
            }
            node = node->next;
        }
        connect(nextHead);
    }
};