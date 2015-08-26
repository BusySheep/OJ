#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

void printTime(int minute, int processedTime) {
	static const int totalTime = (17 - 8) * 60;
	if (minute - processedTime < totalTime) {
		printf("%02d:%02d\n", minute / 60 + 8, (minute % 60));
	}
	else {
		printf("Sorry\n");
	}
}

int main(void) {
	int n;
	int m;
	int k;
	int q;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	int processedTimes[1000];
	for (int i = 0; i < k; i++) {
		scanf("%d", processedTimes + i);
	}

	int finishedTimes[1000];
	queue<pair<int, int>> waitingLine[20];
	int time = 0;
	bool emptyWaiting = false;
	for (int i = 0; i < k || emptyWaiting == false;) {
		int minJ = -1;
		emptyWaiting = true;
		for (int j = 0; j < n; j++) {
			if (waitingLine[j].size() < m && (minJ < 0 || waitingLine[j].size() < waitingLine[minJ].size())) {
				minJ = j;
			}
			if (waitingLine[j].size() > 0) {
				emptyWaiting = false;
			}
		}
		if (minJ >= 0 && i < k) {
			waitingLine[minJ].push(make_pair(i, processedTimes[i]));
			i++;
			continue;
		}
		if (emptyWaiting) {
			break;
		}

		int stepTime = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (waitingLine[j].size() > 0 && waitingLine[j].front().second < stepTime) {
				stepTime = waitingLine[j].front().second;
			}
		}
		time += stepTime;
		for (int j = 0; j < n; j++) {
			if (waitingLine[j].size() > 0) {
				waitingLine[j].front().second -= stepTime;
				if (waitingLine[j].front().second == 0) {
					finishedTimes[waitingLine[j].front().first] = time;
					waitingLine[j].pop();
				}
				else if (waitingLine[j].front().second < 0) {
					exit(1);
				}
			}
		}
	}

	for (int i = 0; i < q; i++) {
		int customer;
		scanf("%d", &customer);
		customer--;
		printTime(finishedTimes[customer], processedTimes[customer]);
	}
	system("pause");
	return 0;
}
