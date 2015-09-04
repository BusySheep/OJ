#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void trim(string& a, string& b) {
	if (a[0] == '-') a.erase(a.begin());
	if (b[0] == '-') b.erase(b.begin());
	for (int i = a.length(); i < b.length(); i++) {
		a.insert(a.begin(), '0');
	}
	for (int i = b.length(); i < a.length(); i++) {
		b.insert(b.begin(), '0');
	}
}

string trim(string num) {
	int i;
	string result;
	if (num[0] == '-') {
		result += '-';
		i = 1;
	} else {
		i = 0;
	}
	for (; i < num.length(); i++) {
		if (num[i] != '0') break;
	}
	for (; i < num.length(); i++) {
		result += num[i];
	}
	if (result == "") result = "0";
	return result;
}

string add(string a, string b) {
	int signA = a[0] == '-' ? -1 : 1;
	int signB = b[0] == '-' ? -1 : 1;
	int carry = 0;
	trim(a, b);
	string result;
	for (int i = a.length() - 1; i >= 0; i--) {
		int digit = signA * (a[i] - '0') + signB * (b[i] - '0') + carry;
		carry = digit / 10;
		digit %= 10;
		if (digit < 0) {
			digit += 10;
			carry--;
		}
		result.insert(result.begin(), digit + '0');
	}
	if (carry > 0) {
		result.insert(result.begin(), carry + '0');
	} else if (carry < 0) {
		int borrowBit = 0;
		for (int i = result.length() - 1; i >= 0; i--) {
			char old = result[i];
			result[i] = 10 - borrowBit - (result[i] - '0') + '0';
			borrowBit = old == '0' ? 0 : 1;
		}
		carry = -carry;
		carry--;
		if (carry != 0) {
			result.insert(result.begin(), carry + '0');
		}
		result.insert(result.begin(), '-');
	}
	return trim(result);
}

int main(){  
    int t;
    cin >> t;
    for (int ri = 1; ri <= t; ri++) {
    	string a, b, c;
    	cin >> a >> b >> c;
    	string sum = add(a, b);
    	string compare = add(sum, "-" + c);
    	bool flag = compare != "0" && compare[0] != '-';
    	printf("Case #%d: %s\n", ri, flag ? "true" : "false");
    }
    return 0;
}