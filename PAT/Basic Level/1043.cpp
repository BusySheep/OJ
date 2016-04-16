#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;
	vector<int> countPATest(256);
	for (int i = 0; i < str.length(); ++i) {
		++countPATest[str[i]];
	}
	static char const * PATest = "PATest";
	while (true) {
		bool allZero = true;
		for (int i = 0; i < 6; ++i) {
			if (countPATest[PATest[i]] > 0) {
				putchar(PATest[i]);
				--countPATest[PATest[i]];
				allZero = false;
			}
		}
		if (allZero) break;
	}
	putchar('\n');
	return 0;
}