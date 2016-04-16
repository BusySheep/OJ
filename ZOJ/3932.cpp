#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		int count = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			if (x > 0) {
				count++;
			}
			count = max(count, x);
		}
		printf("%d\n", count);
	}
	return 0;
}