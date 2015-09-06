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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> q;
        if (root != NULL) q.push(make_pair(root, 0));
        vector<int> levelOrder;
        int oldLevel = 0;
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int level =  q.front().second;
            q.pop();
            if (level == oldLevel) {
                levelOrder.push_back(node->val);
            } else {
                oldLevel = level;
                result.push_back(levelOrder);
                levelOrder.clear();
                levelOrder.push_back(node->val);
            }
            if (node->left != NULL) q.push(make_pair(node->left, level + 1));
            if (node->right != NULL) q.push(make_pair(node->right, level + 1));
        }
        if (levelOrder.size() > 0) result.push_back(levelOrder);
        return result;
    }
};