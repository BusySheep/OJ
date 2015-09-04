#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string n;
	cin >> n;
	for (int i = n.length(); i < 4; i++) {
		n.insert(n.begin(), '0');
	}
	if (n[0] == n[1] && n[0] == n[2] && n[0] == n[3]) {
		printf("%s - %s = 0000\n", n.c_str(), n.c_str());
		return 0;
	}
	do {
		string a = n;
		sort(a.begin(), a.end(), greater<char>());
		string b = n;
		sort(b.begin(), b.end());
		n = to_string(stoi(a) - stoi(b));
		for (int i = n.length(); i < 4; i++) {
			n.insert(n.begin(), '0');
		}
		printf("%s - %s = %s\n", a.c_str(), b.c_str(), n.c_str());
	} while (n != "6174");
	return 0;
}