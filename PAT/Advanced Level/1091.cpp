#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool slice[60][1286][128];
int m, n, l, t;

struct Node {
	int i;
	int j;
	int k;
	Node(int i, int j, int k) :i(i), j(j), k(k){}
};

long bfs(int i, int j, int k) {
	static int dir[6][3] = {
		-1, 0, 0,	//上
		1, 0, 0,	//下
		0, -1, 0,	//前
		0, 1, 0,	//后
		0, 0, -1,	//左
		0, 0, 1		//右
	};
	long count = 0;
	queue<Node> q;
	q.push(Node(i, j, k));
	count++;
	slice[i][j][k] = false;
	while (!q.empty()) {
		Node node = q.front();
		q.pop();
		for (int index = 0; index < 6; index++) {
			Node adj(node.i + dir[index][0], node.j + dir[index][1], node.k + dir[index][2]);

			//边界检查
			if (adj.i < 0 || adj.i >= l) {
				continue;
			}
			if (adj.j < 0 || adj.j >= m) {
				continue;
			}
			if (adj.k < 0 || adj.k >= n) {
				continue;
			}

			if (slice[adj.i][adj.j][adj.k]) {
				q.push(adj);
				count++;
				slice[adj.i][adj.j][adj.k] = false;
			}
		}
	}
	return count;
}

int main(void) {
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				int x;
				scanf("%d", &x);
				slice[i][j][k] = (bool)x;
			}
		}
	}
	long ans = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				long count = 0;
				if (slice[i][j][k] == true) {
					count = bfs(i, j, k);
				}
				if (count >= t) {
					ans += count;
				}
			}
		}
	}
	printf("%ld\n", ans);
	system("pause");
	return 0;
}
