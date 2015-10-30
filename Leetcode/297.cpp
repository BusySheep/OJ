/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "[";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node) result += to_string(node->val);
            else result += "null";
            if (node) {
                q.push(node->left);
                q.push(node->right);
            }
            if (!q.empty()) result += ',';
        }
        result += ']';
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        string current;
        int i;
        for (i = 1; data[i] != ']' && data[i] != ','; i++) {
            current += data[i];
        }
        if (current != "null") root = new TreeNode(stoi(current));
        else return root;
        current.clear();
        queue<TreeNode*> q;
        q.push(root);
        i++;
        while (!q.empty() && data[i] != ']') {
            while (data[i] != ',' && data[i] != ']') {
                current += data[i];
                i++;
            }
            TreeNode* leftChild = nullptr;
            if (current != "null") leftChild = new TreeNode(stoi(current));
            current.clear();
            i++;
            
            while (data[i] != ',' && data[i] != ']') {
                current += data[i];
                i++;
            }
            TreeNode* rightChild = nullptr;
            if (current != "null") rightChild = new TreeNode(stoi(current));
            current.clear();
            i++;
            
            auto node = q.front();
            q.pop();
            node->left = leftChild;
            node->right = rightChild;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));