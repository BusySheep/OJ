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
    TreeNode* doBuild(vector<int>& inorder, vector<int>& postorder, int inBegin, int inEnd, int postBegin, int postEnd, unordered_map<int, int>& indexMap) {
        if (inBegin >= inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd - 1]);
        int rootPosition = indexMap[root->val];
        int leftLength = rootPosition - inBegin;
        root->left = doBuild(inorder, postorder, inBegin, rootPosition, postBegin, postBegin + leftLength, indexMap);
        root->right = doBuild(inorder, postorder, rootPosition + 1, inEnd, postBegin + leftLength, postEnd - 1, indexMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }
        return doBuild(inorder, postorder, 0, inorder.size(), 0, postorder.size(), indexMap);
    }
};