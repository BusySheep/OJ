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
    void solve(TreeNode* root, vector<int>& result) {
        if (!root) return;
        solve(root->left, result);
        result.push_back(root->val);
        solve(root->right, result);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }
};