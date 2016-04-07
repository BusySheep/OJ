#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

long f[21];
void init() {
	f[0] = f[1] = 1;
	for (int i = 2; i < 21; ++i) {
		f[i] = f[i - 1] + f[i - 2];
	}
}

int main() {
	init();
	int T;
	scanf("%d", &T);
	while (T--) {
		int i, gi, j;
		scanf("%d%d%d", &i, &gi, &j);
		int t = -1;
		if ((gi - f[i - 2]) % f[i - 1] == 0) {
			t = (gi - f[i - 2]) / f[i - 1];
		}
		if (t < 1) {
			puts("-1");
		} else {
			long g[21];
			g[0] = 1;
			g[1] = t;
			for (int index = 2; index <= j; ++index) {
				g[index] = g[index - 1] + g[index - 2];
			}
			printf("%ld\n", g[j]);
		}
	}
	return 0;
}