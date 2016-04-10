#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

bool has366Day(int year) {
	if (year % 4 == 0 && year % 100 != 0) {
		return true;
	} else {
		return year % 400 == 0;
	}
}

int monthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve15(string idNumber) {
	string birthDate = idNumber.substr(6, 6);
	string validDate = "000101";
	int minChange = 100;
	for (int year = 0; year <= 99; ++year) {
		for (int month = 1; month <= 12; ++month) {
			int lastDay = monthDay[month - 1];
			if (year % 4 == 0 && month == 2) {
				lastDay = 29;
			}
			for (int day = 1; day <= lastDay; ++day) {
				char date[10];
				sprintf(date, "%02d%02d%02d", year, month, day);
				string temp(date);
				int count = 0;
				for (int i = 0; i < temp.length(); ++i) {
					if (temp[i] != birthDate[i]) {
						++count;
					}
				}
				if (count < minChange) {
					minChange = count;
					validDate = temp;
				}
			}
		}
	}
	string answer = idNumber.substr(0, 6) + validDate + idNumber.substr(12, 3);
	cout << answer << endl;
}

int W[18] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2, 1};

void solve18(string idNumber) {
	string birthDate = idNumber.substr(6, 8);
	string answer;
	int minChange = 100;
	for (int year = 1900; year <= 2011; ++year) {
		int lastMonth = 12;
		if (year == 2011) lastMonth = 4;
		for (int month = 1; month <= lastMonth; ++month) {
			int lastDay = monthDay[month - 1];
			if (has366Day(year) && month == 2) {
				lastDay = 29;
			}
			if (year == 2011 && month == 4) {
				lastDay = 2;
			}
			for (int day = 1; day <= lastDay; ++day) {
				char date[10];
				sprintf(date, "%d%02d%02d", year, month, day);
				string temp(date);
				temp = idNumber.substr(0, 6) + temp + idNumber.substr(14, 4);
				int s = 0;
				for (int i = 0; i < 17; ++i) {
					s += (temp[i] - '0') * W[i];
				}
				int chechsum = (12 - (s % 11)) % 11;
				if (chechsum < 10) temp[17] = chechsum + '0';
				else temp[17] = 'X';

				int count = 0;
				for (int i = 0; i < temp.length(); ++i) {
					if (temp[i] != idNumber[i]) {
						++count;
					}
				}
				if (count < minChange) {
					minChange = count;
					answer = temp;
				}
			}
		}
	}
	cout << answer << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string idNumber;
		cin >> idNumber;
		if (idNumber.length() == 15) {
			solve15(idNumber);
		} else {
			solve18(idNumber);
		}
	}
	return 0;
}