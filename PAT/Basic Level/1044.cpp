#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	static char const * marsHigherDigit[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	static char const * marsLowerDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; ++i) {
		string numberStr;
		getline(cin, numberStr);
		if (numberStr[0] >= '0' && numberStr[0] <= '9') {
			int number = stoi(numberStr);
			int higherDigit = number / 13;
			int lowerDigit = number % 13;
			if (higherDigit > 0) printf("%s", marsHigherDigit[higherDigit]);
			if (higherDigit > 0 && lowerDigit > 0) putchar(' ');
			if (lowerDigit > 0 || higherDigit == 0) printf("%s", marsLowerDigit[lowerDigit]);
			puts("");
		} else {
			int result = 0;
			string higherDigit = numberStr.substr(0, 3);
			for (int i = 1; i < 13; ++i) {
				if (higherDigit == marsHigherDigit[i]) {
					result += i * 13;
				}
			}

			string lowerDigit;
			if (numberStr.length() > 3) {
				lowerDigit = numberStr.substr(4);
			} else if (result == 0) {
				lowerDigit = numberStr;
			}
			for (int i = 0; i < 13; ++i) {
				if (lowerDigit == marsLowerDigit[i]) {
					result += i;
				}
			}
			printf("%d\n", result);
		}
	}
	return 0;
}