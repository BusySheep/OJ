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
private:
    pair<TreeNode*, bool> solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return make_pair(nullptr, false);
        int count = 0;
        auto leftResult = solve(root->left, p, q);
        if (leftResult.first != nullptr) return make_pair(leftResult.first, true);
        auto rightResult = solve(root->right, p, q);
        if (rightResult.first != nullptr) return make_pair(rightResult.first, true);
        if (leftResult.second) count++;
        if (rightResult.second) count++;
        if (root == p || root == q) count++;
        if (count >= 2) return make_pair(root, true);
        else if (count == 1) return make_pair(nullptr, true);
        else return make_pair(nullptr, false);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == q) return p;
        else return solve(root, p, q).first;
    }
};