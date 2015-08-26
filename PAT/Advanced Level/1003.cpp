#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000

int main(void) {
	int n;
	int m;
	int c1;
	int c2;
	vector<int> teamNumber(500, 0);
	vector<pair<int, int>> graph[500];
	vector<int> maxTeamNumber(500, 0);
	vector<int> distance(500, INF);
	vector<bool> flag(500, false);
	vector<int> shortestPathCount(500, 0);
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &teamNumber[i]);
		maxTeamNumber[i] = teamNumber[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l);
		graph[a].push_back(make_pair(b, l));
		graph[b].push_back(make_pair(a, l));
	}
	distance[c1] = 0;
	shortestPathCount[c1] = 1;
	for (int i = 0; i < n; i++) {
		int best_j = -1;
		for (int j = 0; j < n; j++) {
			if ((best_j < 0 || distance[j] < distance[best_j]) && flag[j] == false) {
				best_j = j;
			}
		}
		flag[best_j] = true;
		for (int j = 0; j < graph[best_j].size(); j++) {
			int city = graph[best_j][j].first;
			int len = graph[best_j][j].second;
			if (flag[city] == false) {
				if (distance[city] > distance[best_j] + len) {
					distance[city] = distance[best_j] + len;
					maxTeamNumber[city] = maxTeamNumber[best_j] + teamNumber[city];
					shortestPathCount[city] = shortestPathCount[best_j];
				}
				else if (distance[city] == distance[best_j] + len) {
					shortestPathCount[city] += shortestPathCount[best_j];
					if (maxTeamNumber[city] < maxTeamNumber[best_j] + teamNumber[city]) {
						maxTeamNumber[city] = maxTeamNumber[best_j] + teamNumber[city];
					}
				}
			}
		}
	}
	printf("%d %d\n", shortestPathCount[c2], maxTeamNumber[c2]);
	return 0;
}
