#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <climits>
#include <cmath>
using namespace std;

int charToInt(char c) {
	if (c >= 'a') {
		return c - 'a' + 10;
	} else {
		return c - '0';
	}
}

long calculateNumber(string strNumber, long radix) {
	long num = 0;
	for (int i = 0; i < (int) strNumber.length(); i++) {
		if ((LONG_MAX - charToInt(strNumber[i])) / radix < num) {
			return -1;
		}
		num *= radix;
		num += charToInt(strNumber[i]);
	}
	return num;
}

int main() {
	string n1, n2;
	int tag;
	long radix1;
	cin >> n1 >> n2 >> tag >> radix1;
	if (tag == 2) {
		string temp = n1;
		n1 = n2;
		n2 = temp;
	}
	long num1 = calculateNumber(n1, radix1);
	long minRadix2 = 2;
	for (int i = 0; i < (int) n2.length(); i++) {
		if (charToInt(n2[i]) + 1 > minRadix2) {
			minRadix2 = charToInt(n2[i]) + 1;
		}
	}
	long l = minRadix2;
	long r = max(num1 + 1, l + 1);
	long mid;
	long num2;
	long radix2 = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		num2 = calculateNumber(n2, mid);
		if (num2 == num1) {
			if (radix2 == -1 || mid < radix2) {
				radix2 = mid;
			}
			r = mid - 1;
		} else if (num2 > num1 || num2 == -1) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if (radix2 != -1) {
		printf("%ld\n", radix2);
	} else {
		printf("Impossible\n");
	}
	return 0;
}