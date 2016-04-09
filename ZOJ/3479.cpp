#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string shengxiao[12] = {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Ram", "Monkey", "Rooster", "Dog", "Pig"};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int temp = (3 + 1 - n) % 12;
		cout << shengxiao[temp < 0 ? temp + 12 : temp] << endl;
	}
	return 0;
}