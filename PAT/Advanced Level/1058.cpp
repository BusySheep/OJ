#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Hog {
	int g;
	int s;
	int k;
	Hog operator+(Hog another) const {
		Hog result;
		int carry = 0;
		result.k = k + another.k;
		carry = result.k / 29;
		result.k %= 29;
		result.s = s + another.s + carry;
		carry = result.s / 17;
		result.s %= 17;
		result.g = g + another.g + carry;
		return result;
	}
};

int main() {
	Hog a, b;
	scanf("%d.%d.%d %d.%d.%d", &a.g, &a.s, &a.k, &b.g, &b.s, &b.k);
	Hog c = a + b;
	printf("%d.%d.%d\n", c.g, c.s, c.k);
	return 0;
}