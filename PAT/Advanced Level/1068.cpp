#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 1000
#define MAXM 10

int main(void) {
	int n;
	int m;
	scanf("%d%d", &n, &m);
	int coins[MAXN];
	for (int i = 0; i < n; i++) {
		scanf("%d", &coins[i]);
	}
	sort(coins, coins + n);
	bool d[MAXN + 1][MAXM + 1];//d[i][j]表示从第i,i+1,i+2,...,n-1号硬币是否能选出适当的硬币使得总面值为j
	bool has[MAXN + 1][MAXM + 1];//has[i][j]表示从第i,i+1,i+2,...,n-1号硬币中凑出j面值时是否用上了第i个硬币
	d[n][0] = true;
	for (int j = 1; j <= m; j++) {
		d[n][j] = false;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= m; j++) {
			d[i][j] = d[i + 1][j];
			has[i][j] = false;
			if (j >= coins[i]) {
				if (d[i + 1][j - coins[i]] == true) {
					d[i][j] = true;
					has[i][j] = true;
				}
			}
		}
	}
	if (d[0][m] == false) {
		puts("No Solution");
	}
	else {
		int i = 0;
		while (m > 0) {
			if (has[i][m] == true) {
				printf("%d", coins[i]);
				m -= coins[i];
				if (m > 0) {
					putchar(' ');
				}
				else {
					puts("");
				}
			}
			i++;
		}
	}
	system("pause");
	return 0;
}
