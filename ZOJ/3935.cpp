#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

bool isTriangularNumber(int number) {
	number *= 2;
	int n = sqrt(number);
	return n * (n + 1) == number;
}

bool isHexagonalNumber(int number) {
	int n = sqrt(number / 2);
	for (; n * (2 * n - 1) < number; ++n)
		;
	return n * (2 * n - 1) == number;
}

bool isLeapYear(int year) {
	return (year % 100 != 0 && year % 4 == 0) || year % 400 == 0;
}

bool isTHLYear(int year) {
	return isTriangularNumber(year) && isHexagonalNumber(year) && isLeapYear(year);
}

int main() {
	for (int i = 2016; i <= 990528; ++i) {
		if (isTHLYear(i)) {
			printf("%d\n", i);
		}
	}
	return 0;
}