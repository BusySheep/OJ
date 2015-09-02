#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;

struct Student {
	vector<int> ranks;
	int bestRankIndex;
	Student() : bestRankIndex(0) {}
}students[1000000];

const char course[4] = {'A', 'C', 'M', 'E'};

int main() {
	int n;
	int m;
	cin >> n >> m;
	vector<int> scores[4][301];
	for (int i = 0; i < n; i++) {
		int id, s[4];
		cin >> id >> s[1] >> s[2] >> s[3];
		s[0] = s[1] + s[2] + s[3];
		for (int j = 0; j < 4; j++) {
			scores[j][s[j]].push_back(id);
		}
	}
	for (int i = 0; i < 4; i++) {
		int count = 1;
		int maxScore = i == 0 ? 300 : 100;
		for (int j = maxScore; j >= 0; j--) {
			if (scores[i][j].size() > 0) {
				int oldCount = count;
				for (int k = 0; k < scores[i][j].size(); k++) {
					count++;
					int id = scores[i][j][k];
					students[id].ranks.push_back(oldCount);
					if (oldCount < students[id].ranks[students[id].bestRankIndex]) {
						students[id].bestRankIndex = i;
					}
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int id;
		cin >> id;
		if (id >= 1000000 || students[id].ranks.size() == 0) {
			cout << "N/A" << endl;
		} else {
			int bestRankIndex = students[id].bestRankIndex;
			cout << students[id].ranks[bestRankIndex] << ' ' << course[bestRankIndex] << endl;
		}
	}
	return 0;
}