//
// Created by 柯瀚仰 on 15/3/29.
//
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *insert(TreeNode *root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
        return root;
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    }
    else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    bool flag;
    vector<TreeNode *> stack;
    TreeNode *current;

    BSTIterator(TreeNode *root) {
        if (root != NULL) {
            while (root->left != NULL) {
                stack.push_back(root);
                root = root->left;
            }
            current = root;
            flag = false;
        }
        else {
            current = NULL;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (current == NULL) {
            return false;
        }
        if (flag == false) {
            return true;
        }
        if (current->right != NULL || stack.size() > 0) {
            return true;
        }
        else {
            return false;
        }
    }

    /** @return the next smallest number */
    int next() {
        if (flag == false) {
            flag = true;
            return current->val;
        }
        if (current->right != NULL) {
            current = current->right;
            while (current->left != NULL) {
                stack.push_back(current);
                current = current->left;
            }
            return current->val;
        }
        else {
            current = stack[stack.size() - 1];
            stack.pop_back();
            return current->val;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    TreeNode *root = NULL;
    for (int i = 0; i < 10; i++) {
        root = insert(root, i);
    }
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) {
        cout << i.next() << endl;
    }
    return 0;
}

