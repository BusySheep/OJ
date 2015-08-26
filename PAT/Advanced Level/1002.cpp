#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	vector<double> a(2000, 0);
	
	int k1;
	int k2;
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++) {
		int exp;
		scanf("%d", &exp);
		double coe;
		scanf("%lf", &coe);
		a[exp] = coe;
	}
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++) {
		int exp;
		scanf("%d", &exp);
		double coe;
		scanf("%lf", &coe);
		a[exp] += coe;
	}
	int k3 = 0;
	for (int i = 1999; i >= 0; i--) {
		if (abs(a[i]) > 0.00001) {
			k3++;
		}
	}
	printf("%d", k3);
	for (int i = 1999; i >= 0; i--) {
		if (abs(a[i]) > 0.00001) {
			printf(" %d %.1f", i, a[i]);
		}
	}
	return 0;
}
