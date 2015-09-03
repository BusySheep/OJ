#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Ranklist {
	long id;
	int score;
	int finalRank;
	int localNumber;
	int localRank;
	bool operator<(Ranklist another) const {
		if (score != another.score) {
			return score > another.score;
		} else {
			return id < another.id;
		}
	}
};

int main() {
	int n;
	vector<Ranklist> finalRanklist;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		vector< pair<int, long> > studentScore;
		studentScore.resize(k);
		for (int j = 0; j < k; j++) {
			scanf("%ld%d", &studentScore[j].second, &studentScore[j].first);
		}
		sort(studentScore.begin(), studentScore.end(), greater<pair<int, long> >());
		vector<int> localRanks;
		for (int j = 0; j < k; j++) {
			if (j > 0 && studentScore[j].first == studentScore[j - 1].first) {
				localRanks.push_back(localRanks[j - 1]);
			} else {
				localRanks.push_back(j + 1);
			}
			Ranklist temp;
			temp.id = studentScore[j].second;
			temp.score = studentScore[j].first;
			temp.localNumber = i + 1;
			temp.localRank = localRanks[j];
			finalRanklist.push_back(temp);
		}
	}
	sort(finalRanklist.begin(), finalRanklist.end());
	for (int i = 0; i < (int)finalRanklist.size(); i++) {
		if (i > 0 && finalRanklist[i].score == finalRanklist[i - 1].score) {
			finalRanklist[i].finalRank = finalRanklist[i - 1].finalRank;
		} else {
			finalRanklist[i].finalRank = i + 1;
		}
	}
	printf("%d\n", (int)finalRanklist.size());
	for (int i = 0; i < (int)finalRanklist.size(); i++) {
		printf("%013ld %d %d %d\n", finalRanklist[i].id, finalRanklist[i].finalRank, finalRanklist[i].localNumber, finalRanklist[i].localRank);
	}
	return 0;
}