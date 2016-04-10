#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	int end = sqrt(n);
	for (int i = 2; i <= end; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

bool isGaussianPrime(int x, int y) {
	if (y == 0) {
		swap(x, y);
	}
	if (x == 0) {
		return isPrime(abs(y)) && (abs(y) - 3) % 4 == 0;
	}
	return isPrime(x * x + y * y);
}

int calGCD(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
	int remain = a % b;
	while (remain) {
		a = b;
		b = remain;
		remain = a % b;
	}
	return b;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int x1, x2, y1, y2;
		int count = 0;
		cin >> x1 >> x2 >> y1 >> y2;
		for (int x = x1; x <= x2; ++x) {
			for (int y = y1; y <= y2; ++y) {
				if (isGaussianPrime(x, y)) {
					++count;
				}
			}
		}
		if (count == 0) {
			puts("0/1");
		} else {
			int total = (x2 - x1 + 1) * (y2 - y1 + 1);
			int gcd = calGCD(count, total);
			printf("%d/%d\n", count / gcd, total / gcd);
		}
	}
	return 0;
}