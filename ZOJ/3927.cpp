#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a + b + c + d >= 80) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
	return 0;
}