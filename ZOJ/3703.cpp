#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct State {
	int attractiviness = 0;
	vector<int> solvedProblemTime;
};

int getBestPenaltyTime(vector<int> solvedProblemTime) {
	if (solvedProblemTime.size() == 0) return 0;

	sort(solvedProblemTime.begin(), solvedProblemTime.end());
	int sum = solvedProblemTime[0];
	for (int i = 1; i < solvedProblemTime.size(); ++i) {
		solvedProblemTime[i] += solvedProblemTime[i - 1];
		sum += solvedProblemTime[i];
	}
	return sum;
}

State best(State const& a, State const& b) {
	if (a.attractiviness != b.attractiviness) {
		return a.attractiviness > b.attractiviness ? a : b;
	} else if (a.solvedProblemTime.size() != b.solvedProblemTime.size()) {
		return a.solvedProblemTime.size() > b.solvedProblemTime.size() ? a : b;
	} else {
		return getBestPenaltyTime(a.solvedProblemTime) < getBestPenaltyTime(b.solvedProblemTime) ? a : b;
	}
}

void printVector(vector<int> const& v) {
	for (int i = 0; i < v.size(); ++i) {
		if (i) putchar(' ');
		printf("%d", v[i]);
	}
	puts("");
}

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		int T;
		int n;
		scanf("%d%d", &T, &n);
		int times[50];
		int attractivinesses[50];
		for (int i = 0; i < n; ++i) {
			scanf("%d", &times[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &attractivinesses[i]);
		}
		State dp[51][1001];
		State answer;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= T; ++j) {
				if (j >= times[i - 1]) {
					State newState = dp[i - 1][j - times[i - 1]];
					newState.attractiviness += attractivinesses[i - 1];
					newState.solvedProblemTime.push_back(times[i - 1]);
					dp[i][j] = best(dp[i - 1][j], newState);
				} else {
					dp[i][j] = dp[i - 1][j];
				}
				answer = best(answer, dp[i][j]);
			}
		}
		printf("%d %d %d\n", answer.attractiviness, (int) answer.solvedProblemTime.size(), getBestPenaltyTime(answer.solvedProblemTime));
	}
	return 0;
}