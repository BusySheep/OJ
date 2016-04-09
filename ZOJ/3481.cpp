#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void solve(vector<int>& ts, string delimiting) {
	if (ts.size() == 1) {
		for (int i = 2; i < 3000; ++i) {
			ts.push_back(i * ts[0]);
		}
	} else {
		sort(ts.begin(), ts.end());
		auto endIt = unique(ts.begin(), ts.end());
		ts.erase(endIt, ts.end());
		for (int i = 0; i < 3000; ++i) {
			ts.push_back(ts.back() + 1);
		}
	}
	string line;
	string newLine;
	getline(cin, line);
	while (line != delimiting) {
		newLine = "";
		for (int i = 0; i < line.length(); ++i) {
			if (line[i] == '\t') {
				int nextTabPosition = *upper_bound(ts.begin(), ts.end(), newLine.length());
				while (newLine.length() < nextTabPosition) {
					newLine.push_back(' ');
				}
			} else {
				newLine.push_back(line[i]);
			}
		}
		cout << newLine << endl;
		getline(cin, line);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%*s");
		vector<int> ts;
		int temp;
		scanf("%d", &temp);
		ts.push_back(temp);
		while (getchar() == ',') {
			scanf("%d", &temp);
			ts.push_back(temp);
		}
		getchar();
		getchar();
		string delimiting;
		cin >> delimiting;
		getchar();
		solve(ts, delimiting);
		puts("");
	}
	return 0;
}