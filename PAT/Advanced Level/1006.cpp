#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

struct Time {
	int h;
	int m;
	int s;
	bool operator<(const Time& another) {
		if (h != another.h) {
			return h < another.h;
		} else if (m != another.m) {
			return m < another.m;
		} else {
			return s < another.s;
		}
	}
	void scan() {
		scanf("%d:%d:%d", &h, &m, &s);
	}
	Time() {}
	Time(int h, int m, int s) : h(h), m(m), s(s) {}
};

int main() {
	int m;
	cin >> m;
	string unlockPerson;
	string lockPerson;
	Time latest(-1, 0, 0);
	Time earliest(25, 0, 0);
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		Time in, out;
		in.scan();
		out.scan();
		if (in < earliest) {
			earliest = in;
			unlockPerson = name;
		}
		if (latest < out) {
			latest = out;
			lockPerson = name;
		}
	}
	cout << unlockPerson << ' ' << lockPerson << endl;
	return 0;
}