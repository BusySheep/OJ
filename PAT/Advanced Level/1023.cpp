#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string multy2(string n) {
	string result;
	int carry = 0;
	for (int i = n.length() - 1; i >= 0; i--) {
		int temp = n[i] - '0';
		temp *= 2;
		temp += carry;
		carry = temp / 10;
		temp %= 10;
		result.push_back(temp + '0');
	}
	result.push_back(carry + '0');
	reverse(result.begin(), result.end());
	int i;
	for (i = 0; result[i] == '0'; i++)
		;
	string temp = result.c_str() + i;
	return temp;
}

int main() {
	string n;
	cin >> n;
	int count[10];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < n.length(); i++) {
		count[n[i] - '0']++;
	}
	n = multy2(n);
	for (int i = 0; i < n.length(); i++) {
		count[n[i] - '0']--;
	}
	int i;
	for (i = 0; i < 10; i++) {
		if (count[i] != 0) {
			break;
		}
	}
	if (i < 10) {
		puts("No");
	} else {
		puts("Yes");
	}
	cout << n << endl;
	return 0;
}