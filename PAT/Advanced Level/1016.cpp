#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

struct Time {
	int day;
	int hour;
	int minute;
	void print() {
		printf("%02d:%02d:%02d", day, hour, minute);
	}
	int operator-(Time time) {
		return (((day * 24) + hour) * 60 + minute) - (((time.day * 24) + time.hour) * 60 + time.minute);
	}
};

bool operator < (Time time1, Time time2) {
	if (time1.day != time2.day) {
		return time1.day < time2.day;
	}
	else if (time1.hour != time2.hour) {
		return time1.hour < time2.hour;
	}
	else {
		return time1.minute < time2.minute;
	}
}

struct Customer {
	vector <pair<Time, bool>> time;
	double totalAmount;
	int totalMinute;
};

class Charge {
	
public:
	static vector<double> rate;
	static double countCharge(Time begin, Time end) {
		double charge = 0;
		int beginHour = begin.day * 24 + begin.hour;
		int endHour = end.day * 24 + end.hour;
		if (beginHour != endHour) {
			charge += (60 - begin.minute) * rate[begin.hour];
			charge += (end.minute) * rate[end.hour];
		}
		else {
			charge += (end.minute - begin.minute) * rate[begin.hour];
		}
		for (int i = beginHour + 1; i < endHour; i++) {
			charge += 60 * rate[i % 24];
		}
		return charge;
	}
};

vector<double> Charge::rate;

int main(void) {
	vector<double> rate(24, 0);
	for (int i = 0; i < 24; i++) {
		scanf("%lf", &rate[i]);
		rate[i] /= 100;
	}
	Charge::rate = rate;
	int n;
	scanf("%d", &n);
	map<string, Customer> bills;
	int month;
	for (int i = 0; i < n; i++) {
		char temp[21];
		scanf("%s", temp);
		string name = temp;
		Time time;
		scanf("%d:%d:%d:%d", &month, &time.day, &time.hour, &time.minute);
		bool flag;
		scanf("%s", temp);
		flag = !strcmp(temp, "on-line");
		bills[name].time.push_back(make_pair(time, flag));
	}
	for (auto it = bills.begin(); it != bills.end(); it++) {
		pair<string, Customer> bill = *it;
		sort(bill.second.time.begin(), bill.second.time.end());
		bill.second.totalAmount = 0;
		bill.second.totalMinute = 0;
		for (int i = 0; i < bill.second.time.size(); i++) {
			if (bill.second.time[i].second == false) {
				if (i > 0 && bill.second.time[i - 1].second == true) {
					double charge = Charge::countCharge(bill.second.time[i - 1].first, bill.second.time[i].first);
					int lastingTime = bill.second.time[i].first - bill.second.time[i - 1].first;
					bill.second.totalAmount += charge;
					bill.second.totalMinute += lastingTime;
				}
			}
		}
		(*it).second.totalAmount = bill.second.totalAmount;
		(*it).second.totalMinute = bill.second.totalMinute;
	}
	for (auto it = bills.begin(); it != bills.end(); it++) {
		pair<string, Customer> bill = *it;
		if (bill.second.totalMinute > 0) {
			printf("%s %02d\n", bill.first.c_str(), month);
		}
		sort(bill.second.time.begin(), bill.second.time.end());
		for (int i = 0; i < bill.second.time.size(); i++) {
			if (bill.second.time[i].second == false) {
				if (i > 0 && bill.second.time[i - 1].second == true) {
					bill.second.time[i - 1].first.print();
					putchar(' ');
					bill.second.time[i].first.print();
					double charge = Charge::countCharge(bill.second.time[i - 1].first, bill.second.time[i].first);
					int lastingTime = bill.second.time[i].first - bill.second.time[i - 1].first;
					printf(" %d $%.2f\n", lastingTime, charge);
				}
			}
		}
		if (bill.second.totalMinute > 0) {
			printf("Total amount: $%.2f\n", bill.second.totalAmount);
		}
	}
	system("pause");
	return 0;
}
