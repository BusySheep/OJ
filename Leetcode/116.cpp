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
        if (!root->left) return;
        auto node = root;
        TreeLinkNode* pre = nullptr;
        while (node) {
            if (pre) pre->next = node->left;
            node->left->next = node->right;
            pre = node->right;
            node = node->next;
        }
        connect(root->left);
    }
};