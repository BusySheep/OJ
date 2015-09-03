#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main() {
	char temp[10001];
	gets(temp);
	string s1 = temp;
	gets(temp);
	string s2 = temp;
	vector<bool> hash(128, false);
	for (int i = 0; i < s2.length(); i++) {
		hash[s2[i]] = true;
	}
	for (int i = 0; i < s1.length(); i++) {
		if (hash[s1[i]] == false) {
			putchar(s1[i]);
		}
	}
	puts("");
	return 0;
}