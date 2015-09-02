#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	int radix;
	cin >> n;
	while (n >= 0) {
		cin >> radix;
		vector<int> number;
		int temp = n;
		do {
			number.push_back(temp % radix);
			temp /= radix;
		} while (temp > 0);
		int afterReverse = 0;
		for (int i = 0; i < number.size(); i++) {
			afterReverse *= radix;
			afterReverse += number[i];
		}
		if (isPrime(afterReverse) && isPrime(n)) {
			puts("Yes");
		} else {
			puts("No");
		}
		cin >> n;
	}
	return 0;
}