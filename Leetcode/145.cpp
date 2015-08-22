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
    void doPostorderTraversal(TreeNode* root, vector<int>& result) {
        if (root == NULL) {
            return;
        }
        doPostorderTraversal(root->left, result);
        doPostorderTraversal(root->right, result);
        result.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        doPostorderTraversal(root, result);
        return result;
    }
};