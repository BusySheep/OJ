#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

inline char indexToChar(int index) {
	static char result[3] = {'W', 'T', 'L'};
	return result[index];
}

int main() {
	double bets[3][3];
	double maxBet[3] = {0, 0, 0};
	int maxIndex[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%lf", &bets[i][j]);
			if (bets[i][j] > maxBet[i]) {
				maxBet[i] = bets[i][j];
				maxIndex[i] = j;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		printf("%c ", indexToChar(maxIndex[i]));
	}
	printf("%.2f\n", (maxBet[0] * maxBet[1] * maxBet[2] * 0.65 - 1) * 2);
	return 0;
}