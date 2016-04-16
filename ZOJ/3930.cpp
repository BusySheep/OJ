#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c== '/';
}

string expandDice(int diceTimes, string dNumber) {
	if (diceTimes == 0) {
		return "0";
	}
	string result;
	if (diceTimes > 1) {
		result += '(';
	}

	for (int i = 0; i < diceTimes; ++i) {
		if (i) result += " + ";
		result += "[d";
		result += dNumber;
		result += ']';
	}

	if (diceTimes > 1) {
		result += ')';
	}
	return result;
}

int main() {
	int T;
	scanf("%d", &T);
	getchar();
	while (T--) {
		string diceNotation;
		getline(cin, diceNotation);
		string currentInteger;

		string result;

		for (int i = 0; i < diceNotation.length(); ++i) {
			if (diceNotation[i] == 'd') {
				int diceTimes;
				if (i > 0 && isDigit(diceNotation[i - 1])) {
					diceTimes = atoi(currentInteger.c_str());
					currentInteger = "";
				} else {
					diceTimes = 1;
				}

				string dNumber;
				while (++i < diceNotation.length() && isDigit(diceNotation[i])) {
					dNumber += diceNotation[i];
				}
				i--;

				result += expandDice(diceTimes, dNumber);
			} else if (isDigit(diceNotation[i])) {
				currentInteger += diceNotation[i];
				if (i + 1 == diceNotation.length() || (!isDigit(diceNotation[i + 1]) && diceNotation[i + 1] != 'd')) {
					result += currentInteger;
					currentInteger = "";
				}
			} else if (diceNotation[i] == ' ' || diceNotation[i] == '\t') {
				// do nothing
			} else if (isOperator(diceNotation[i])) {
				result += ' ';
				result += diceNotation[i];
				result += ' ';
			} else {
				result += diceNotation[i];
			}
		}
		result += " = [Result]";
		cout << result << endl;
	}
	return 0;
}