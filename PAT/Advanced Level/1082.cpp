#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void doRead(int n, bool beginFlag, bool endFlag) {
	static char digit[10][5] = {
		"ling",
		"yi",
		"er",
		"san",
		"si",
		"wu",
		"liu",
		"qi",
		"ba",
		"jiu"
	};
	static char place[4][5] = {
		"",
		"Shi",
		"Bai",
		"Qian"
	};
	char number[5];
	sprintf(number, "%d", n);
	int len = strlen(number);
	if (!beginFlag && (!endFlag || n != 0)) {
		if (len < 4) {
			printf(" ling");
		}
	}
	vector<bool> flag(4, false);
	for (int i = len - 1; i >= 0; i--) {
		if (number[i] != '0') {
			break;
		}
		flag[i] = true;
	}
	vector<bool> flag2(4, false);//∑¿÷π¡¨–¯∂¡¡„
	for (int i = 0; i < len; i++) {
		if (number[i] == '0') {
			flag2[i] = true;
		}
	}
	for (int i = 0; number[i]; i++) {
		if (flag[i] == false && (i == 0 || flag2[i] == false || flag2[i - 1] == false)) {
			if (!(i == 0 && beginFlag)) {
				putchar(' ');
			}
			printf("%s", digit[number[i] - '0']);
			if (number[i] != '0') {
				if (i != len - 1) {
					putchar(' ');
				}
				printf("%s", place[len - 1 - i]);
			}
		}
	}
}

void readNumber(int n) {
	if (n == 0) {
		printf("ling\n");
		return;
	}
	int number[3];
	int count = 0;
	while (n > 0) {
		number[count++] = n % 10000;
		n /= 10000;
	}
	char place[3][5] = {
		"",
		"Wan",
		"Yi"
	};
	for (int i = count - 1; i >= 0; i--) {
		doRead(number[i], i == count - 1, i == 0);
		if (i != 0) {
			putchar(' ');
		}
		printf("%s", place[i]);
	}
	puts("");
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);
	if (n < 0) {
		printf("Fu ");
		n = -n;
	}
	readNumber(n);
	system("pause");
	return 0;
}
