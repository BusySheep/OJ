#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> selectedIndex;

void solve(vector<int>& numbers, int index, int start) {
	int end = index + numbers.size() - 6 + 1;
	for (int i = start; i < end; ++i) {
		selectedIndex.push_back(i);
		if (index == 5) {
			for (int j = 0; j < selectedIndex.size(); ++j) {
				if (j) putchar(' ');
				printf("%d", numbers[selectedIndex[j]]);
			}
			puts("");
		} else {
			solve(numbers, index + 1, i + 1);
		}
		selectedIndex.pop_back();
	}
}

int main() {
	int k;
	scanf("%d", &k);
	while (k > 0) {
		vector<int> numbers(k);
		for (int i = 0; i < k; ++i) {
			scanf("%d", &numbers[i]);
		}
		solve(numbers, 0, 0);
		scanf("%d", &k);
		if (k > 0) puts("");
	}
	return 0;
}