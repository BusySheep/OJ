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

    pair<TreeNode*, TreeNode*> flattenLeft(TreeNode* root) {
        // The function will not return <NULL, NULL>
        if (root->left == NULL && root->right == NULL) return make_pair(root, root);
        
        pair<TreeNode*, TreeNode*> rightP;
        if (root->left) {
            auto leftP = flattenLeft(root->left);
            root->left = NULL;
            rightP = flattenRight(leftP.first, leftP.second, root->right);
            root->right = rightP.first;
        } else {
            rightP = flattenLeft(root->right);
        }
        return make_pair(root, rightP.second);
    }
    
    pair<TreeNode*, TreeNode*> flattenRight(TreeNode* leftHead, TreeNode* leftTail, TreeNode* root) {
        
        // The program can make sure that leftHead and leftTail can not be NULL
        
        if (root == NULL) return make_pair(leftHead, leftTail);
        
        TreeNode* tail;
        if (root->left == NULL && root->right == NULL) {
            tail = root;
        } else if (root->left) {
            auto leftP = flattenLeft(root->left);
            root->left = NULL;
            auto rightP = flattenRight(leftP.first, leftP.second, root->right);
            root->right = rightP.first;
            tail = rightP.second;
        } else {
            auto rightP = flattenLeft(root->right);
            root->right = rightP.first;
            tail = rightP.second;
        }
        
        leftTail->right = root;
        
        return make_pair(leftHead, tail);
    }
    
public:

    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flattenLeft(root);
    }
    
};