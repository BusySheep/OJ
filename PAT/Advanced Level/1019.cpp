//12:35:30
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int b;
	cin >> n >> b;
	vector<int> number;
	do {
		number.push_back(n % b);
		n /= b;
	} while (n > 0);
	int i;
	for (i = 0; i < number.size() / 2; i++) {
		if (number[i] != number[number.size() - 1 - i]) {
			break;
		}
	}
	if (i < number.size() / 2) {
		puts("No");
	} else {
		puts("Yes");
	}
	for (i = number.size() - 1; i >= 0; i--) {
		cout << number[i];
		if (i > 0) {
			cout << ' ';
		}
	}
	cout << endl;
	return 0;
}
//12:41:30
