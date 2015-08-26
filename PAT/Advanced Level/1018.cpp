#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int bikes[501];//current bike number
vector<pair<int, int>> stations[501];
int capacity;
int n;
int dest;
int m;

//answer
int minTime = INT_MAX;
int minSentBike = INT_MAX;
int minBackBike = INT_MAX;
vector<int> bestPath;

void dfs(int vertex) {

	//recursive data
	static int time = 0;
	static int sentBike = 0;
	static int backBike = 0;
	static vector<int> path;

	//status data
	static bool visited[501];

	if (vertex == dest) {
		if (time < minTime) {
			minTime = time;
			minSentBike = sentBike;
			minBackBike = backBike;
			bestPath = path;
		}
		else if (time == minTime) {
			if (sentBike < minSentBike) {
				minSentBike = sentBike;
				minBackBike = backBike;
				bestPath = path;
			}
			else if (sentBike == minSentBike) {
				if (backBike < minBackBike) {
					minBackBike = backBike;
					bestPath = path;
				}
			}
		}
		return;
	}

	visited[vertex] = true;
	for (int i = 0; i < stations[vertex].size(); i++) {
		int& station = stations[vertex][i].first;
		if (!visited[station]) {
			time += stations[vertex][i].second;
			int oldSentBike = sentBike;
			int oldBackBike = backBike;
			if (bikes[station] + backBike < capacity / 2) {
				sentBike += capacity / 2 - backBike - bikes[station];
				backBike = 0;
			}
			else {
				backBike += bikes[station] - capacity / 2;
			}
			path.push_back(station);
			
			dfs(station);

			time -= stations[vertex][i].second;
			sentBike = oldSentBike;
			backBike = oldBackBike;
			path.pop_back();
		}
	}
	visited[vertex] = false;
}

int main(void) {
	scanf("%d%d%d%d", &capacity, &n, &dest, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", bikes + i + 1);
	}
	for (int i = 0; i < m; i++) {
		int s1, s2;
		int time;
		scanf("%d%d%d", &s1, &s2, &time);
		stations[s1].push_back(make_pair(s2, time));
		stations[s2].push_back(make_pair(s1, time));
	}
	dfs(0);
	printf("%d ", minSentBike);
	printf("0");
	for (int i = 0; i < bestPath.size(); i++) {
		printf("->%d", bestPath[i]);
	}
	printf(" %d\n", minBackBike);
	return 0;
}

