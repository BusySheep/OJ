#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1000000000

int vertexNumber(const char *p, int n) {
	return p[0] == 'G' ? atoi(p + 1) - 1 + n : atoi(p) - 1;
}

int main(void) {
	int n;
	int m;
	int k;
	int ds;
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	vector<vector<pair<int, int>>> city(n + m, vector<pair<int, int>>());
	vector<vector<int>> distance(m, vector<int>(n + m, INF));
	vector<bool> flag(m, true);
	vector<int> minDistance(m, INF);
	vector<double> averageDistance(m, 0);
	for (int i = 0; i < k; i++) {
		char p1[10];
		char p2[10];
		int dist;
		scanf("%s%s%d", p1, p2, &dist);
		int v1 = vertexNumber(p1, n);
		int v2 = vertexNumber(p2, n);
		city[v1].push_back(make_pair(v2, dist));
		city[v2].push_back(make_pair(v1, dist));
	}
	int bestLocation = -1;
	for (int index = 0; index < m; index++) {
		vector<bool> visited(n + m, false);
		distance[index][n + index] = 0;
		for (int i = 0; i < n + m; i++) {
			int minJ = -1;
			for (int j = 0; j < n + m; j++) {
				if (!visited[j] && (minJ == -1 || distance[index][j] < distance[index][minJ])) {
					minJ = j;
				}
			}
			visited[minJ] = true;
			if (minJ < n) {
				averageDistance[index] += (double)distance[index][minJ] / n;
				if (minDistance[index] > distance[index][minJ]) {
					minDistance[index] = distance[index][minJ];
				}
				if (distance[index][minJ] > ds) {
					flag[index] = false;
				}
			}
			for (int j = 0; j < city[minJ].size(); j++) {
				if (!visited[city[minJ][j].first]) {
					if (distance[index][city[minJ][j].first] > distance[index][minJ] + city[minJ][j].second) {
						distance[index][city[minJ][j].first] = distance[index][minJ] + city[minJ][j].second;
					}
				}
			}
		}
		if (flag[index] == true && (bestLocation == -1 || minDistance[bestLocation] < minDistance[index])) {
			bestLocation = index;
		}
		else if (flag[index] == true && (bestLocation == -1 || (minDistance[bestLocation] == minDistance[index]) && averageDistance[bestLocation] > averageDistance[index])) {
			bestLocation = index;
		}
	}
	if (bestLocation != -1) {
		printf("G%d\n", bestLocation + 1);
		printf("%.1f %.1f\n", (double)minDistance[bestLocation], averageDistance[bestLocation]);
	}
	else {
		printf("No Solution\n");
	}
	return 0;
}
