#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> numbers(n);
	vector<int> maxNumber(n);
	vector<int> minNumber(n);
	vector<int> answer;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &numbers[i]);
		maxNumber[i] = numbers[i];
		if (i > 0) maxNumber[i] = max(maxNumber[i], maxNumber[i - 1]);
	}
	for (int i = n - 1; i >= 0; --i) {
		minNumber[i] = numbers[i];
		if (i < n - 1) minNumber[i] = min(minNumber[i], minNumber[i + 1]);
		if (numbers[i] == maxNumber[i] && numbers[i] == minNumber[i]) {
			answer.push_back(numbers[i]);
		}
	}
	printf("%d\n", (int) answer.size());
	for (int i = answer.size() - 1; i >= 0; --i) {
		if (i < answer.size() - 1) putchar(' ');
		printf("%d", answer[i]);
	}
	puts("");
	return 0;
}