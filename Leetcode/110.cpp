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
    pair<int, bool> doIsBalanced(TreeNode* root) {
        if (root == NULL) return make_pair(0, true);
        pair<int, bool> leftResult = doIsBalanced(root->left);
        pair<int, bool> rightResult = doIsBalanced(root->right);
        int diff = leftResult.first - rightResult.first;
        int height = max(leftResult.first, rightResult.first) + 1;
        return make_pair(height, leftResult.second && rightResult.second && diff >= -1 && diff <= 1);
    }
public:
    bool isBalanced(TreeNode* root) {
        return doIsBalanced(root).second;
    }
};