#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

char digitToChar(int digit) {
	if (digit < 10) {
		return digit + '0';
	} else {
		return digit - 10 + 'A';
	}
}

string to13(int n) {
	string result;
	result.push_back(digitToChar(n / 13));
	result.push_back(digitToChar(n % 13));
	return result;
}

int main() {
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	printf("#%s%s%s\n", to13(r).c_str(), to13(g).c_str(), to13(b).c_str());
	return 0;
}