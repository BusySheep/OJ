#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string english[10] = {
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};
	string number;
	cin >> number;
	int sum = 0;
	for (int i = 0; i < number.length(); i++) {
		sum += number[i] - '0';
	}
	stringstream ss;
	do {
		ss << sum % 10;
		sum /= 10;
	} while (sum > 0);
	string reverseNumber = ss.str();
	for (int i = reverseNumber.length() - 1; i >= 0; i--) {
		cout << english[reverseNumber[i] - '0'];
		if (i > 0) {
			cout << ' ';
		}
	}
	cout << endl;
	return 0;
}