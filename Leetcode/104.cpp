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
    int maxDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int maxDepth = 0;
        if (root!= NULL) q.push(make_pair(root, 1));
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (node->left == NULL && node->right == NULL) {
                maxDepth = level;
            }
            if (node->left != NULL) q.push(make_pair(node->left, level + 1));
            if (node->right != NULL) q.push(make_pair(node->right, level + 1));
        }
        return maxDepth;
    }
};