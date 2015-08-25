#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

void scanPoly(vector<double>& poly) {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int exponent;
		double coeffcient;
		cin >> exponent >> coeffcient;
		poly[exponent] = coeffcient;
	}
}

int main() {
	vector<double> poly1(1001, 0);
	vector<double> poly2(1001, 0);
	vector<double> poly3(2001, 0);
	scanPoly(poly1);
	scanPoly(poly2);
	for (int i = 0; i < 1001; i++) {
		if (poly1[i] != 0) {
			for (int j = 0; j < 1001; j++) {
				if (poly2[j] != 0) {
					poly3[i + j] += poly1[i] * poly2[j];
				}
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 2001; i++) {
		if (poly3[i] != 0) {
			count++;
		}
	}
	cout << count;
	for (int i = 2000; i >= 0; i--) {
		if (poly3[i] != 0) {
			printf(" %d %.1f", i, poly3[i]);
		}
	}
	cout << endl;
	return 0;
}