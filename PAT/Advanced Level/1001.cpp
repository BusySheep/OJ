#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);
	int c = a + b;
	char result[100];
	bool flag = c >= 0 ? false : true;
	sprintf(result, "%d", abs(c));
	if (flag) {
		putchar('-');
	}
	int len = strlen(result);
	for (int i = 0; result[i]; i++) {
		putchar(result[i]);
		if ((len - i) % 3 == 1 && i != len - 1) {
			putchar(',');
		}
	}
	puts("");
	return 0;
}
