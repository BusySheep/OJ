#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> sequence(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}
	int i = 0;
	int j = 0;
	int sum = 0;
	int maxSum = -1;
	int bestI;
	int bestJ;
	while (j < n) {
		sum += sequence[j];
		if (maxSum < sum) {
			maxSum = sum;
			bestI = i;
			bestJ = j;
		}
		j++;
		if (sum < 0) {
			sum = 0;
			i = j;
		}
	}
	if (maxSum >= 0) {
		printf("%d %d %d\n", maxSum, sequence[bestI], sequence[bestJ]);
	} else {
		printf("%d %d %d\n", 0, sequence[0], sequence[n - 1]);
	}
	return 0;
}