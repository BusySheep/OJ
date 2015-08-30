#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int m;
vector<vector<pair<int, int> > > citys;
vector<pair<int, pair<int, int> > > destroyedRoads;

void input() {
	cin >> n >> m;
	citys.resize(n);
	for (int i = 0; i < m; i++) {
		int city1, city2, cost, status;
		cin >> city1 >> city2 >> cost >> status;
		city1--;
		city2--;
		if (status == 1) {
			citys[city1].push_back(make_pair(city2, cost));
			citys[city2].push_back(make_pair(city1, cost));
		} else {
			destroyedRoads.push_back(make_pair(cost, make_pair(city1, city2)));
		}
	}
}

int findRoot(int x, vector<int>& dijSet) {
	if (dijSet[x] == x) {
		return x;
	} else {
		return dijSet[x] = findRoot(dijSet[x], dijSet);
	}
}

void mergeDijSet(int a, int b, vector<int>& dijSet) {
	int rootA = findRoot(a, dijSet);
	int rootB = findRoot(b, dijSet);
	if (rootA != rootB) {
		dijSet[rootB] = rootA;
	}
}

void dfs(int city, int occupiedCity, vector<bool>& visited, vector<int>& dijSet) {
	visited[city] = true;
	for (int i = 0; i < citys[city].size(); i++) {
		int adjCity = citys[city][i].first;
		if (!visited[adjCity] && adjCity != occupiedCity) {
			mergeDijSet(city, adjCity, dijSet);
			dfs(adjCity, occupiedCity, visited, dijSet);
		}
	}
}

int calculateRepairCost(int occupiedCity) {
	vector<int> dijSet(n, 0);
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) {
		dijSet[i] = i;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i] && i != occupiedCity) {
			dfs(i, occupiedCity, visited, dijSet);
		}
	}
	int result = 0;
	for (int i = 0; i < destroyedRoads.size(); i++) {
		int city1 = destroyedRoads[i].second.first;
		int city2 = destroyedRoads[i].second.second;
		if (city1 == occupiedCity || city2 == occupiedCity) {
			continue;
		}
		if (findRoot(city1, dijSet) != findRoot(city2, dijSet)) {
			mergeDijSet(city1, city2, dijSet);
			result += destroyedRoads[i].first;
		}
	}
	int root = -1;
	for (int i = 0; i < n; i++) {
		if (i != occupiedCity) {
			if (root == -1) {
				root = findRoot(i, dijSet);
			}
			if (root != findRoot(i, dijSet)) {
				result = INT_MAX;
			}
		}
	}
	return result;
}

int main() {
	input();
	sort(destroyedRoads.begin(), destroyedRoads.end());
	int maxRepairCost = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int repairCost = calculateRepairCost(i);
		if (repairCost == 0) {
			continue;
		}
		if (maxRepairCost < repairCost) {
			maxRepairCost = repairCost;
			ans.clear();
			ans.push_back(i);
		} else if (maxRepairCost == repairCost) {
			ans.push_back(i);
		}
	}
	if (ans.size() == 0) {
		printf("0");
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i] + 1);
		if (i < ans.size() - 1) {
			putchar(' ');
		}
	}
	puts("");
	return 0;
}