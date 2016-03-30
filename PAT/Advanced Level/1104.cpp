#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	long n;
	scanf("%ld", &n);
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		double number;
		scanf("%lf", &number);
		sum += number * (i - 0 + 1) * (n - i);
	}

	printf("%.2f\n", sum);
	return 0;
}