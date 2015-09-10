#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

struct SegNode {
	long long val;
	long long addMark;
	SegNode() : val(0), addMark(0) {}
};

vector<long long> numbers;
vector<SegNode> segTree;

void buildTree(int nodeIndex, int l, int r) {
	if (l >= r) return;
	if (segTree.size() <= nodeIndex) {
		segTree.resize(nodeIndex + 1);
	}
	if (l == r - 1) {
		segTree[nodeIndex].val = numbers[l];
		return;
	}
	int mid = (l + r) / 2;
	buildTree(nodeIndex * 2 + 1, l, mid);
	buildTree(nodeIndex * 2 + 2, mid, r);
	segTree[nodeIndex].val = segTree[nodeIndex * 2 + 1].val + segTree[nodeIndex * 2 + 2].val;
}

void pushDown(int nodeIndex, int l, int r) {
	if (segTree[nodeIndex].addMark != 0) {
		int mid = (l + r) / 2;
		if (nodeIndex * 2 + 1 < segTree.size()) {
			segTree[nodeIndex * 2 + 1].addMark += segTree[nodeIndex].addMark;
			segTree[nodeIndex * 2 + 1].val += segTree[nodeIndex].addMark * (mid - l);
		}
		if (nodeIndex * 2 + 2 < segTree.size()) {
			segTree[nodeIndex * 2 + 2].addMark += segTree[nodeIndex].addMark;
			segTree[nodeIndex * 2 + 2].val += segTree[nodeIndex].addMark * (r - mid);
		}
		segTree[nodeIndex].addMark = 0;
	}
}

void add(long long addValue, int nodeIndex, int addL, int addR, int l, int r) {
	if (addL >= addR) return;
	if (addL >= r || addR <= l) return;
	else if (addL <= l && addR >= r) {
		segTree[nodeIndex].addMark += addValue;
		segTree[nodeIndex].val += addValue * (r - l);
		return;
	}
	pushDown(nodeIndex, l, r);
	int mid = (l + r) / 2;
	add(addValue, nodeIndex * 2 + 1, addL, addR, l, mid);
	add(addValue, nodeIndex * 2 + 2, addL, addR, mid, r);
	segTree[nodeIndex].val = segTree[nodeIndex * 2 + 1].val + segTree[nodeIndex * 2 + 2].val;
}

long long query(int nodeIndex, int queryL, int queryR, int l, int r) {
	if (queryL >= queryR) return 0;
	if (queryL >= r || queryR <= l) return 0;
	else if (queryL <= l && queryR >= r) return segTree[nodeIndex].val;
	pushDown(nodeIndex, l, r);
	int mid = (l + r) / 2;
	return query(nodeIndex * 2 + 1, queryL, queryR, l, mid) + query(nodeIndex * 2 + 2, queryL, queryR, mid, r);
}

int main() {
	int n;
	int q;
	scanf("%d%d", &n, &q);
	numbers.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &numbers[i]);
	}
	buildTree(0, 0, numbers.size());
	for (int i = 0; i < q; i++) {
		char oper[2];
		int operL, operR;
		scanf("%s%d%d", oper, &operL, &operR);
		operL--;
		if (string(oper) == "Q") {
			printf("%lld\n", query(0, operL, operR, 0, numbers.size()));
		} else {
			long long addValue;
			scanf("%lld", &addValue);
			add(addValue, 0, operL, operR, 0, numbers.size());
		}
	}
	return 0;
}