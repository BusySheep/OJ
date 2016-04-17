#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int countX = 0;
	int countY = 0;
	for (int i = 0; i < n; ++i) {
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		int sum = x1 + y1;
		if (x2 == sum && y2 != sum) {
			countY++;
		} else if (y2 == sum && x2 != sum) {
			countX++;
		}
	}
	printf("%d %d\n", countX, countY);
	return 0;
}