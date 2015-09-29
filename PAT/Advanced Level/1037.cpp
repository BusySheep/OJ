#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int nc;
	scanf("%d", &nc);
	vector<int> couponPosi;
	vector<int> couponNega;
	for (int i = 0; i < nc; i++) {
		int x;
		scanf("%d", &x);
		if (x > 0) couponPosi.push_back(x);
		else couponNega.push_back(x);
	}
	int np;
	scanf("%d", &np);
	vector<int> productPosi;
	vector<int> productNega;
	for (int i = 0; i < np; i++) {
		int x;
		scanf("%d", &x);
		if (x > 0) productPosi.push_back(x);
		else productNega.push_back(x);
	}
	sort(couponPosi.begin(), couponPosi.end(), greater<int>());
	sort(productPosi.begin(), productPosi.end(), greater<int>());
	sort(couponNega.begin(), couponNega.end());
	sort(productNega.begin(), productNega.end());
	long result = 0;
	for (int i = 0; i < couponPosi.size() && i < productPosi.size(); i++) {
		result += (long) couponPosi[i] * productPosi[i];
	}
	for (int i = 0; i < couponNega.size() && i < productNega.size(); i++) {
		result += (long) couponNega[i] * productNega[i];
	}
	printf("%ld\n", result);
	return 0;
}