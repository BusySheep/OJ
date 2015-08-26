#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	int n;
	double p;
	double r;
	scanf("%d%lf%lf", &n, &p, &r);
	vector<vector<int>> chain(n, vector<int>());
	vector<int> supplier(n, 0);
	int root;
	for (int i = 0; i < n; i++) {
		scanf("%d", &supplier[i]);
		if (supplier[i] == -1) {
			root = i;
		}
		else {
			chain[supplier[i]].push_back(i);
		}
	}
	int maxLevel = -1;
	int count = 0;
	queue<pair<int, int>> q;
	vector<bool> visited(n, false);
	q.push(make_pair(root, 0));
	visited[root] = true;
	while (!q.empty()) {
		int person = q.front().first;
		int level = q.front().second;
		q.pop();
		if (level > maxLevel) {
			maxLevel = level;
			count = 1;
		}
		else if (level == maxLevel) {
			count++;
		}
		for (int i = 0; i < chain[person].size(); i++) {
			if (!visited[chain[person][i]]) {
				q.push(make_pair(chain[person][i], level + 1));
			}
		}
	}
	printf("%.2f %d\n", p * pow(1 + r / 100, maxLevel), count);
	system("pause");
	return 0;
}
