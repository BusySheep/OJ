/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if ((long) (root->val - p->val) * (root->val - q->val) <= 0) return root;
        TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
        if (leftResult) return leftResult;
        TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);
        if (rightResult) return rightResult;
    }
};