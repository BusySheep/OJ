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
	int oldFloor = 0;
	int countTime = 0;
	for (int i = 0; i < n; i++) {
		int newFloor;
		cin >> newFloor;
		if (newFloor > oldFloor) {
			countTime += (newFloor - oldFloor) * 6;
		} else {
			countTime += (oldFloor - newFloor) * 4;
		}
		countTime += 5;
		oldFloor = newFloor;
	}
	cout << countTime << endl;
	return 0;
}