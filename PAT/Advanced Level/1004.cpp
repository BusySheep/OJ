#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	int n;
	int m;
	vector<int> tree[100];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int id;
		int k;
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++) {
			int x;
			scanf("%d", &x);
			tree[id].push_back(x);
		}
	}
	queue<pair<int, int>> q;
	vector<int> ans(100, 0);
	q.push(make_pair(1, 0));
	int level;
	while (!q.empty()) {
		int node = q.front().first;
		level = q.front().second;
		q.pop();
		if (tree[node].size() == 0) {
			ans[level]++;
		}
		else {
			for (int i = 0; i < tree[node].size(); i++) {
				q.push(make_pair(tree[node][i], level + 1));
			}
		}
	}
	for (int i = 0; i <= level; i++) {
		if (i) {
			putchar(' ');
		}
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}
