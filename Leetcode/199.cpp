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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<pair<TreeNode*, int>> q;
        int currentLevel = 0;
        int previousElement = root->val;
        q.push(make_pair(root, currentLevel));
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            auto node = temp.first;
            int level = temp.second;
            if (level != currentLevel) {
                result.push_back(previousElement);
                currentLevel = level;
            }
            previousElement = node->val;
            if (node->left) q.push(make_pair(node->left, level + 1));
            if (node->right) q.push(make_pair(node->right, level + 1));
        }
        result.push_back(previousElement);
        return result;
    }
};