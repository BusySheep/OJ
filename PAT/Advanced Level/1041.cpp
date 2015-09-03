#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int n;
	int count[10001];
	int order[10001];
	memset(count, 0, sizeof(count));
	memset(order, 0, sizeof(order));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (count[x] == 0) {
			order[x] = i;
		}
		count[x]++;
	}
	int minOrder = 100001;
	int winNumber;
	for (int i = 1; i <= 10000; i++) {
		if (count[i] == 1 && minOrder > order[i]) {
			minOrder = order[i];
			winNumber = i;
		}
	}
	if (minOrder == 100001) {
		puts("None");
	} else {
		printf("%d\n", winNumber);
	}
	return 0;
}