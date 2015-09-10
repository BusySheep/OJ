#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

struct SegNode {
	int colors;
	int changeToColor;
	SegNode() : colors(1), changeToColor(0) {}
};

vector<SegNode> segTree;

void buildTree(int nodeIndex, int l, int r) {
	if (l >= r) return;
	if (segTree.size() <= nodeIndex) segTree.resize(nodeIndex + 1);
	if (l == r - 1) return;
	int mid = (l + r) / 2;
	buildTree(nodeIndex * 2 + 1, l, mid);
	buildTree(nodeIndex * 2 + 2, mid, r);
}

void pushDown(int nodeIndex, int l, int r) {
	if (segTree[nodeIndex].changeToColor != 0) {
		int mid = (l + r) / 2;
		if (nodeIndex * 2 + 1 < segTree.size()) {
			segTree[nodeIndex * 2 + 1].changeToColor = segTree[nodeIndex].changeToColor;
			segTree[nodeIndex * 2 + 1].colors = segTree[nodeIndex].changeToColor;
		}
		if (nodeIndex * 2 + 2 < segTree.size()) {
			segTree[nodeIndex * 2 + 2].changeToColor = segTree[nodeIndex].changeToColor;
			segTree[nodeIndex * 2 + 2].colors = segTree[nodeIndex].changeToColor;
		}
		segTree[nodeIndex].changeToColor = 0;
	}
}

void changeColor(int color, int nodeIndex, int changeL, int changeR, int l, int r) {
	if (changeL >= r || changeR <= l) return;
	else if (changeL <= l && changeR >= r) {
		segTree[nodeIndex].changeToColor = color;
		segTree[nodeIndex].colors = color;
		return;
	}
	pushDown(nodeIndex, l, r);
	int mid = (l + r) / 2;
	changeColor(color, nodeIndex * 2 + 1, changeL, changeR, l, mid);
	changeColor(color, nodeIndex * 2 + 2, changeL, changeR, mid, r);
	segTree[nodeIndex].colors = segTree[nodeIndex * 2 + 1].colors | segTree[nodeIndex * 2 + 2].colors;
}

int query(int nodeIndex, int queryL, int queryR, int l, int r) {
	if (queryL >= r || queryR <= l) return 0;
	else if (queryL <= l && queryR >= r) return segTree[nodeIndex].colors;
	pushDown(nodeIndex, l, r);
	int mid = (l + r) / 2;
	return query(nodeIndex * 2 + 1, queryL, queryR, l, mid) | query(nodeIndex * 2 + 2, queryL, queryR, mid, r);
}

int countColor(int colors) {
	int count = 0;
	while (colors > 0) {
		count += colors % 2;
		colors /= 2;
	}
	return count;
}

int genColor(int colorIndex) {
	return 1 << colorIndex;
}

int main() {
	int L;
	int T;
	int O;
	scanf("%d%d%d", &L, &T, &O);
	buildTree(0, 0, L);
	for (int i = 0; i < O; i++) {
		char oper[2];
		int operL, operR;
		scanf("%s%d%d", oper, &operL, &operR);
		if (operL > operR) {
			int t = operL;
			operL = operR;
			operR = t;
		}
		operL--;
		if (string(oper) == "P") {
			int colors = query(0, operL, operR, 0, L);
			printf("%d\n", countColor(colors));
		} else {
			int changeToColorIndex;
			scanf("%d", &changeToColorIndex);
			changeToColorIndex--;
			int changeToColor = genColor(changeToColorIndex);
			changeColor(changeToColor, 0, operL, operR, 0, L);
		}
	}
	return 0;
}