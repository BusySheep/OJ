#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

vector<int> factors;

void genFactors(long n) {
	vector<int> large;
	for (long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			factors.push_back(i);
			if (i * i != n) {
				large.push_back(n / i);
			}
		}
	}
	for (int i = large.size() - 1; i >= 0; i--) {
		factors.push_back(large[i]);
	}
	factors.push_back(n);
}

bool isConsecutive(int i, int j) {
	for (int k = i + 1; k < j; k++) {
		if (factors[k] != factors[k - 1] + 1) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	genFactors(n);
	int i = 0;
	int j = 1;
	long product = factors[0];
	int bestI = 0;
	int bestJ = 0;
	while (n >= product && j <= factors.size()) {
		if (n % product == 0 && isConsecutive(i, j)) {
			if (j - i > bestJ - bestI) {
				bestI = i;
				bestJ = j;
			}
			if (j == factors.size()) break;
			product *= factors[j];
			j++;
		} else {
			if (j == factors.size()) break;
			product /= factors[i];
			i++;
			product *= factors[j];
			j++;
		}
	}
	printf("%d\n", bestJ - bestI);
	for (int k = bestI; k < bestJ; k++) {
		cout << factors[k];
		if (k < bestJ - 1) {
			cout << '*';
		} else {
			cout << endl;
		}
	}
	return 0;
}