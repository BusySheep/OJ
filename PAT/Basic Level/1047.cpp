#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> scores(1001);
	for (int i = 0; i < n; ++i) {
		int teamNumber;
		int score;
		scanf("%d-%*d %d", &teamNumber, &score);
		scores[teamNumber] += score;
	}
	int championTeam = 1;
	for (int i = 2; i <= 1000; ++i) {
		if (scores[championTeam] < scores[i]) {
			championTeam = i;
		}
	}
	printf("%d %d\n", championTeam, scores[championTeam]);
	return 0;
}