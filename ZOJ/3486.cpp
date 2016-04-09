#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> count(10000);
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			++count[x];
		}
		int maxID = 1001;
		for (int i = 1002; i <= 9999; ++i) {
			if (count[i] >= count[maxID]) {
				maxID = i;
			}
		}
		printf("%d\n", maxID);
	}
	return 0;
}