#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<string, int>> seats(n + 1);
	for (int i = 0; i < n; ++i) {
		string idNumber;
		int contestSeatNumber;
		int practiceSeatNumber;
		cin >> idNumber >> practiceSeatNumber >> contestSeatNumber;
		seats[practiceSeatNumber] = make_pair(idNumber, contestSeatNumber);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int practiceSeatNumber;
		cin >> practiceSeatNumber;
		cout << seats[practiceSeatNumber].first << ' ' << seats[practiceSeatNumber].second << endl;
	}
	return 0;
}