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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        stack<TreeNode*> oddLevel;
        stack<TreeNode*> evenLevel;
        if (root != NULL) oddLevel.push(root);
        while (!oddLevel.empty() || !evenLevel.empty()) {
            vector<int> levelOrder;
            if (!oddLevel.empty()) {
                while (!oddLevel.empty()) {
                    TreeNode* node = oddLevel.top();
                    levelOrder.push_back(node->val);
                    if (node->left != NULL) evenLevel.push(node->left);
                    if (node->right != NULL) evenLevel.push(node->right);
                    oddLevel.pop();
                }
            } else {
                while (!evenLevel.empty()) {
                    TreeNode* node = evenLevel.top();
                    levelOrder.push_back(node->val);
                    if (node->right != NULL) oddLevel.push(node->right);
                    if (node->left != NULL) oddLevel.push(node->left);
                    evenLevel.pop();
                }
            }
            result.push_back(levelOrder);
        }
        return result;
    }
};