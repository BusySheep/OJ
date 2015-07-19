#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void doRightSideView(TreeNode *root, int level, vector<int>& result) {
        if (root == NULL) {
            return;
        }
        if (result.size() <= level) {
            result.push_back(root->val);
        }
        else {
            result[level] = root->val;
        }
        doRightSideView(root->left, level + 1, result);
        doRightSideView(root->right, level + 1, result);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        doRightSideView(root, 0, result);
        return result;
    }
};

