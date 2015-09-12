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
    int currentSum;
public:
    Solution() : currentSum(0) {}
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        currentSum += root->val;
        bool flag = false;
        if (root->left == NULL && root->right == NULL) flag = currentSum == sum;
        flag = flag || (hasPathSum(root->left, sum) || hasPathSum(root->right, sum));
        currentSum -= root->val;
        return flag;
    }
};