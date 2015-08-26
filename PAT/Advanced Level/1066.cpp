#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class AVLTree {
private:
	vector<vector<int>> tree;
	vector<int> key;
	vector<int> height;
	int root;
	int getHeight(int id) {
		if (id == -1) {
			return -1;
		}
		if (tree[id].size() == 0) {
			return height[id] = 0;
		}
		else {
			return height[id];
		}
	}
	int singleRotateWithLeft(int root) {
		int left = tree[root][0];
		tree[root][0] = tree[left][1];
		tree[left][1] = root;
		height[root] = max(getHeight(tree[root][0]), getHeight(tree[root][1])) + 1;
		height[left] = max(getHeight(tree[left][0]), getHeight(tree[left][1])) + 1;
		return left;
	}
	int doubleRotateWithLeft(int root) {
		tree[root][0] = singleRotateWithRight(tree[root][0]);
		return singleRotateWithLeft(root);
	}
	int singleRotateWithRight(int root) {
		int right = tree[root][1];
		tree[root][1] = tree[right][0];
		tree[right][0] = root;
		height[root] = max(getHeight(tree[root][0]), getHeight(tree[root][1])) + 1;
		height[right] = max(getHeight(tree[right][0]), getHeight(tree[right][1])) + 1;
		return right;
	}
	int doubleRotateWithRight(int root) {
		tree[root][1] = singleRotateWithLeft(tree[root][1]);
		return singleRotateWithRight(root);
	}
	void doInsert(int id, int& root) {
		if (root == -1) {
			root = id;
		}
		else if (key[id] < key[root]) {
			const int& left = tree[root][0];
			const int& right = tree[root][1];
			doInsert(id, tree[root][0]);
			if (getHeight(left) - getHeight(right) == 2) {
				if (key[id] < key[left]) {
					root = singleRotateWithLeft(root);
				}
				else {
					root = doubleRotateWithLeft(root);
				}
			}
		}
		else if (key[id] > key[root]) {
			const int& left = tree[root][0];
			const int& right = tree[root][1];
			doInsert(id, tree[root][1]);
			if (getHeight(right) - getHeight(left) == 2) {
				if (key[id] > key[right]) {
					root = singleRotateWithRight(root);
				}
				else {
					root = doubleRotateWithRight(root);
				}
			}
		}
		else {
			//do nothing
		}
		height[root] = max(getHeight(tree[root][0]), getHeight(tree[root][1])) + 1;
	}

public:
	void insert(int x) {
		int id = key.size();
		key.push_back(x);
		tree.push_back(vector<int>(2, -1));
		height.push_back(0);
		if (id != 0) {
			doInsert(id, this->root);
		}
		else {
			this->root = 0;
		}
	}
	int getRoot() {
		return key[root];
	}
};

int main(void) {
	int n;
	AVLTree tree;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		tree.insert(x);
	}
	printf("%d\n", tree.getRoot());
	system("pause");
	return 0;
}


