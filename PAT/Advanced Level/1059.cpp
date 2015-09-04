#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(long n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	long n;
	cin >> n;
	vector< pair<long, int> > factors;
	if (n == 1) factors.push_back(make_pair(1, 1));
	long temp = n;
	for (long i = 2; temp > 1; i++) {
		if (isPrime(i) && temp % i == 0) {
			int count = 0;
			while (temp % i == 0) {
				count++;
				temp /= i;
			}
			factors.push_back(make_pair(i, count));
		}
	}
	printf("%ld=", n);
	for (int i = 0; i < factors.size(); i++) {
		if (i) putchar('*');
		printf("%ld", factors[i].first);
		if (factors[i].second > 1) {
			printf("^%d", factors[i].second);
		}
	}
	puts("");
	return 0;
}