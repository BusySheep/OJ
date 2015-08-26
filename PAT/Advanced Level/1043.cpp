#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int nodes[1000];
bool flag = true;
bool mirrorFlag = false;

void bstPreOrder(int begin, int end) {
	if (begin >= end) return;
	int value = nodes[begin];
	int mid = end;
	for (int i = begin + 1; i < end; i++) {
		if (nodes[i] >= value) {
			mid = i;
			break;
		}
	}

	//check
	for (int i = mid; i < end; i++) {
		if (nodes[i] < value) {
			flag = false;
			return;
		}
	}

	bstPreOrder(begin + 1, mid);
	bstPreOrder(mid, end);
}

void mirrorPreOrder(int begin, int end) {
	if (begin >= end) return;
	int value = nodes[begin];
	int mid = end;
	for (int i = begin + 1; i < end; i++) {
		if (nodes[i] < value) {
			mid = i;
			break;
		}
	}

	//check
	for (int i = mid; i < end; i++) {
		if (nodes[i] >= value) {
			flag = false;
			return;
		}
	}

	mirrorPreOrder(begin + 1, mid);
	mirrorPreOrder(mid, end);
}

vector<int> ans;

void bstPostOrder(int begin, int end) {
	if (begin >= end) return;
	int value = nodes[begin];
	int mid = end;
	for (int i = begin + 1; i < end; i++) {
		if (nodes[i] >= value) {
			mid = i;
			break;
		}
	}
	bstPostOrder(begin + 1, mid);
	bstPostOrder(mid, end);
	ans.push_back(value);
}

void mirrorPostOrder(int begin, int end) {
	if (begin >= end) return;
	int value = nodes[begin];
	int mid = end;
	for (int i = begin + 1; i < end; i++) {
		if (nodes[i] < value) {
			mid = i;
			break;
		}
	}
	mirrorPostOrder(begin + 1, mid);
	mirrorPostOrder(mid, end);
	ans.push_back(value);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", nodes + i);
	}
	bstPreOrder(0, n);
	if (flag == false) {
		flag = true;
		mirrorFlag = true;
		mirrorPreOrder(0, n);
	}

	if (flag == false) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
		if (!mirrorFlag) {
			bstPostOrder(0, n);
		}
		else {
			mirrorPostOrder(0, n);
		}
		for (int i = 0; i < ans.size(); i++) {
			printf("%d", ans[i]);
			if (i == ans.size() - 1) {
				puts("");
			}
			else {
				putchar(' ');
			}
		}
	}
	system("pause");
	return 0;
}
