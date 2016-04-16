#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	vector<char> countChar(256);
	for (int i = 0; i < str.length(); ++i) {
		char c = str[i];
		if (c >= 'A' && c <= 'Z') {
			c += 'a' - 'A';
		}
		++countChar[c];
	}
	char answer = 0;
	for (char i = 'a'; i <= 'z'; ++i) {
		if (countChar[i] > countChar[answer]) {
			answer = i;
		}
	}
	printf("%c %d\n", answer, countChar[answer]);
	return 0;
}