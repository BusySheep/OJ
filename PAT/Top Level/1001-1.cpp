#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class BattleCitys {

public:
	BattleCitys(int n) : citys(n, vector<int>()) {}

private:
	vector<vector<int>> citys;
	vector<pair<int, pair<int, int>>> badRoads;//cost, city1, city2


	void doFindArt(int v, int parent, vector<int>& art) {
		static vector<int> num(citys.size(), 0);
		static vector<int> low(citys.size(), 0);
		static vector<bool> artFlag(citys.size(), false);
		static int counter = 0;

		int childCount = 0;
		low[v] = num[v] = ++counter;
		for (int i = 0; i < citys[v].size(); i++) {
			int w = citys[v][i];
			if (!num[w]) {
				childCount++;
				doFindArt(w, v, art);
				if (parent >= 0 && low[w] >= num[v] && artFlag[v] == false) {
					art.push_back(v);
					artFlag[v] = true;	//prevent push twice
				}
				else if (parent < 0 && childCount > 1 && artFlag[v] == false) {	//the root has more than one child, so it is a articulation point
					art.push_back(v);
					artFlag[v] = true;
				}
				low[v] = min(low[v], low[w]);
			}
			else if (parent >= 0 && parent != w) {	//back edge
				low[v] = min(low[v], num[w]);
			}
		}
	}

	int getRoot(int v, vector<int>& disjSet) {
		if (disjSet[v] == -1) {
			return v;
		}
		else {
			return disjSet[v] = getRoot(disjSet[v], disjSet);
		}
	}

	void merge(int v, int w, vector<int>& disjSet) {
		int root1 = getRoot(v, disjSet);
		int root2 = getRoot(w, disjSet);
		if (root1 != root2) {
			disjSet[root1] = root2;
		}
		else {
			exit(1);
		}
	}

	void initialDisjSet(int artPoint, vector<int>& disjSet, int& areaNumber) {
		vector<bool> visited(citys.size(), false);
		for (int i = 0; i < citys.size(); i++) {
			dfs(i, disjSet, artPoint, visited, areaNumber);	//initial the disjSet
		}
		/*
		从
		for (int i = 0; i < citys[artPoint].size(); i++) {
			dfs(citys[artPoint][i], disjSet, artPoint, visited, areaNumber);	//initial the disjSet
		}
		改为了
		for (int i = 0; i < citys.size(); i++) {
			dfs(i, disjSet, artPoint, visited, areaNumber);	//initial the disjSet
		}
		就对了
		目前还未想明白为什么
		*/
	}

	void dfs(int v, vector<int>& disjSet, int art, vector<bool>& visited, int& areaNumber) {
		if (v == art) return;
		if (visited[v]) return;
		visited[v] = true;
		for (int i = 0; i < citys[v].size(); i++) {
			if (visited[citys[v][i]] == false && citys[v][i] != art) {
				merge(v, citys[v][i], disjSet);
				areaNumber--;
				dfs(citys[v][i], disjSet, art, visited, areaNumber);
			}
		}
	}

public:
	vector<int> findArt() {
		vector<int> art;
		//找割点的程序目前还有bug
		//doFindArt(0, -1, art);
		for (int i = 0; i < citys.size(); i++) {
			art.push_back(i);
		}
		return art;
	}

	vector<int> findMostImportantCity() {
		sort(badRoads.begin(), badRoads.end());
		vector<int> art = findArt();
		int maxTotalCost = 0;
		vector<int> ans;
		bool repairFlag = false;

		for (int artIndex = 0; artIndex < art.size(); artIndex++) {
			int areaNumber = citys.size() - 1;
			vector<int> disjSet(citys.size(), -1);
			int artPoint = art[artIndex];
			initialDisjSet(artPoint, disjSet, areaNumber);

			int totalCost = 0;
			for (int i = 0; i < badRoads.size() && areaNumber > 1; i++) {
				int& c1 = badRoads[i].second.first;
				int& c2 = badRoads[i].second.second;
				if (c1 != artPoint && c2 != artPoint) {
					if (getRoot(c1, disjSet) != getRoot(c2, disjSet)) {
						totalCost += badRoads[i].first;
						merge(c1, c2, disjSet);
						repairFlag = true;
						areaNumber--;
					}
				}
			}
			//whether the whole country is connected
			if (areaNumber > 1) {
				//the whole country is not connected
				repairFlag = true;
				totalCost = INT_MAX;
			}
			if (totalCost > maxTotalCost) {
				ans.clear();
				ans.push_back(artPoint);
				maxTotalCost = totalCost;
			}
			else if (totalCost == maxTotalCost) {
				ans.push_back(artPoint);
			}
		}
		sort(ans.begin(), ans.end());
		if (repairFlag) {
			return ans;
		}
		else {
			return vector<int>();
		}
	}

	void addUsingRoad(int c1, int c2) {
		citys[c1].push_back(c2);
		citys[c2].push_back(c1);
	}

	void addDestroyedRoad(int c1, int c2, int cost) {
		badRoads.push_back(make_pair(cost, make_pair(c1, c2)));
	}

};

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	if (m <= 0) {
		puts("0");
		return 0;
	}
	BattleCitys citys(n);
	for (int i = 0; i < m; i++) {
		int c1, c2;
		int cost;
		int status;
		scanf("%d%d%d%d", &c1, &c2, &cost, &status);
		c1--;
		c2--;
		if (status) {
			citys.addUsingRoad(c1, c2);
		}
		else {
			citys.addDestroyedRoad(c1, c2, cost);
		}
	}

	vector<int> importantCity = citys.findMostImportantCity();
	for (int i = 0; i < importantCity.size(); i++) {
		printf("%d%c", importantCity[i] + 1, i < importantCity.size() - 1 ? ' ' : '\n');
	}
	if (importantCity.size() == 0) {
		printf("0\n");
	}
	return 0;
}

