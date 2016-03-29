#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void printVector(vector<int>& numbers) {
	for (int i = 0; i < numbers.size(); ++i) {
		if (i) putchar(' ');
		printf("%d", numbers[i]);
	}
	puts("");
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> numbers(n);
	vector<int> answer;
	vector<int> maxNumberFromFront(n);
	vector<int> minNumberToEnd(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &numbers[i]);
		if (i) maxNumberFromFront[i] = max(numbers[i], maxNumberFromFront[i - 1]);
		else maxNumberFromFront[i] = numbers[i];
	}

	for (int i = n - 1; i >= 0; --i) {
		if (i < n - 1) minNumberToEnd[i] = min(numbers[i], minNumberToEnd[i + 1]);
		else minNumberToEnd[i] = numbers[i];

		if (numbers[i] == maxNumberFromFront[i] && numbers[i] == minNumberToEnd[i]) {
			answer.push_back(numbers[i]);
		}
	}
	reverse(answer.begin(), answer.end());

	printf("%lu\n", answer.size());
	printVector(answer);
	return 0;
}