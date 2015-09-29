#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

vector<pair<int, int> > tree;
set<int> numbers;
vector<int> treeVal;
set<int>::iterator it;

void fillTree(int node) {
	if (tree[node].first != -1) {
		fillTree(tree[node].first);
	}
	treeVal[node] = *it;
	it++;
	if (tree[node].second != -1) {
		fillTree(tree[node].second);
	}
}

vector<int> bfs() {
	vector<int> result;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		result.push_back(treeVal[node]);
		if (tree[node].first != -1) {
			q.push(tree[node].first);
		}
		if (tree[node].second != -1) {
			q.push(tree[node].second);
		}
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	tree.resize(n);
	treeVal.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> tree[i].first >> tree[i].second;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		numbers.insert(x);
	}
	it = numbers.begin();
	fillTree(0);
	vector<int> ans = bfs();
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i < ans.size() - 1) {
			cout << ' ';
		} else {
			cout << endl;
		}
	}
	return 0;
}