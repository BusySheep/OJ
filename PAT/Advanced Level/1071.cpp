#include <string>
#include <map>
#include <cstdio>
#include <iostream>
using namespace std;

char lowerCase(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 'a';
	} else {
		return c;
	}
}

bool isAlphanumerical(char c) {
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z');
}

int main() {
	string temp;
	map<string, int> count;
	while (true) {
		char c = getchar();
		c = lowerCase(c);
		if (isAlphanumerical(c)) {
			temp.push_back(c);
		} else {
			if (temp != "") {
				count[temp]++;
				temp.clear();
			}
		}

		if (c == '\n') break;
	}
	int maxCount = 0;
	string result;
	for (auto it = count.begin(); it != count.end(); it++) {
		if (it->second > maxCount) {
			maxCount = it->second;
			result = it->first;
		}
	}
	cout << result << ' ' << maxCount << endl;
	return 0;
}