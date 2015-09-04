#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string trim(string num) {
	// remove the 0 and '-' in the head
	string result;
	int i;
	for (i = 0; i < num.length(); i++) {
		if (num[i] != '0' && num[i] != '-') break;
	}
	if (i == 0) return num;
	for (; i < num.length(); i++) {
		result.push_back(num[i]);
	}
	if (result == "") result = "0";
	return result;
}

string removeDot(string num) {
	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '.') {
			num.erase(num.begin() + i);
			return num;
		}
	}
	return num;
}

string getDigits(string num) {
	return trim(removeDot(num));
}

/*
 * if num == "0" or num == "0.000...000", it will return 0
 */
int countPower(string num) {
	num = trim(num);
	if (num == "0") return 0;
	int i;
	for (i = 0; i < num.length(); i++) {
		if (num[i] == '.') break;
	}
	if (i > 0) return i;
	for (; i < num.length(); i++) {
		if (num[i] != '.' && num[i] != '0') return (-i + 1);
	}
	return 0;
}

bool isNegative(string num) {
	return num[0] == '-';
}

string standardFormat(string num, int accuracy) {
	string digits = getDigits(num).substr(0, accuracy);
	for (int i = digits.length(); i < accuracy; i++) {
		digits.push_back('0');
	}
	string sign = "";
	if (isNegative(num)) sign = "-";
	return sign + "0." + digits + "*10^" + to_string(countPower(num));
}

int main() {
	int n;
	string a, b;
	cin >> n >> a >> b;
	string standardA = standardFormat(a, n);
	string standardB = standardFormat(b, n);
	if (standardA == standardB) {
		cout << "YES " << standardA << endl;
	} else {
		cout << "NO" << ' ' << standardA << ' ' << standardB << endl;
	}
	return 0;
}