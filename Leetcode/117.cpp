/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<pair<TreeLinkNode*, int>> q;
        int currentLevel = 0;
        TreeLinkNode* pre = nullptr;
        q.push(make_pair(root, currentLevel));
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            auto node = temp.first;
            auto level = temp.second;
            if (pre) {
                if (level == currentLevel) {
                    pre->next = node;
                } else {
                    pre->next = nullptr;
                    currentLevel = level;
                }
            }
            pre = node;
            if (node->left) q.push(make_pair(node->left, level + 1));
            if (node->right) q.push(make_pair(node->right, level + 1));
            if (q.empty()) node->next = nullptr;
        }
    }
};