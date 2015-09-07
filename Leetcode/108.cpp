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
    TreeNode* doConvert(vector<int>& nums, int begin, int end) {
        if (begin >= end) return NULL;
        if (begin >= end - 1) {
            return new TreeNode(nums[begin]);
        }
        int mid = (begin + end) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = doConvert(nums, begin, mid);
        node->right = doConvert(nums, mid + 1, end);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return doConvert(nums, 0, nums.size());
    }
};