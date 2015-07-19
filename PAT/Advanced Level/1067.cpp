#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	int numbers[100000];
	int positions[100000];
	scanf("%d", &n);
	vector<bool> visited(n, false);
	int errorNumber = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &numbers[i]);
		positions[numbers[i]] = i;
		if (numbers[i] != i) {
			errorNumber++;
		}
		else {
			visited[i] = true;
		}
	}
	int circleNumber = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			while (!visited[i]) {
				visited[i] = true;
				i = positions[i];
			}
			circleNumber++;
		}
	}
	int answer = errorNumber + circleNumber;
	if (numbers[0] != 0) {
		//0在某个环内
		answer -= 2;
	}
	printf("%d\n", answer);
	system("pause");
	return 0;
}
