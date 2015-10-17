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
    void doPreorderTraversal(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        result.push_back(root->val);
        doPreorderTraversal(root->left, result);
        doPreorderTraversal(root->right, result);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        doPreorderTraversal(root, result);
        return result;
    }
};