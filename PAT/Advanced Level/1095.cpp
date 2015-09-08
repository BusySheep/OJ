#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

struct Time {
	int hour;
	int minute;
	int second;
	bool operator<(Time another) const {
		if (hour != another.hour) return hour < another.hour;
		else if (minute != another.minute) return minute < another.minute;
		else return second < another.second;
	}
	bool operator-(Time another) const {
		return ((hour - another.hour) * 60 + (minute - another.minute)) * 60 + (second - another.second);
	}
	int toInt() {
		return (hour * 60 + minute) * 60 + second;
	}
	static Time intToTime(int intTime) {
		Time result;
		result.second = intTime % 60;
		intTime /= 60;
		result.minute = intTime % 60;
		result.hour = intTime / 60;
		return result;
	}
};

struct CarTime {
	string plateNumber;
	int totalTime;
	CarTime(string plateNumber, int totalTime) : plateNumber(plateNumber), totalTime(totalTime) {}
};

int main() {
	int n;
	int k;
	scanf("%d%d", &n, &k);
	map< string, vector< pair<int, string> > > carsCrossing;
	for (int i = 0; i < n; i++) {
		char tempPlate[8];
		Time tempTime;
		char tempStatus[4];
		scanf("%s %d:%d:%d %s", tempPlate, &tempTime.hour, &tempTime.minute, &tempTime.second, tempStatus);
		carsCrossing[tempPlate].push_back(make_pair(tempTime.toInt(), tempStatus));
	}
	vector<CarTime> carTimes;
	vector< pair<int, string> > eventTable;
	for (map< string, vector< pair<int, string> > >::iterator it = carsCrossing.begin(); it != carsCrossing.end(); it++) {
		sort(it->second.begin(), it->second.end());
		vector< pair<int, string> >& timeTable = it->second;
		int newLength = 0;
		int totalTime = 0;
		for (int i = 0; i < timeTable.size(); i++) {
			if (timeTable[i].second == "in" && i + 1 < timeTable.size() && timeTable[i + 1].second == "out") {
				totalTime += timeTable[i + 1].first - timeTable[i].first;
				eventTable.push_back(timeTable[i]);
				timeTable[newLength++] = timeTable[i];
				i++;
				eventTable.push_back(timeTable[i]);
				timeTable[newLength++] = timeTable[i];
			}
		}
		timeTable.resize(newLength);
		carTimes.push_back(CarTime(it->first, totalTime));
	}
	sort(eventTable.begin(), eventTable.end());
	vector<int> eventTimes(eventTable.size(), 0);
	vector<int> countCars(eventTable.size() + 1, 0); // 之后用upper_bound查找会错位1，正好这里就直接错位1抵消
	for (int i = 0; i < eventTable.size(); i++) {
		eventTimes[i] = eventTable[i].first;
		if (eventTable[i].second == "in") {
			countCars[i + 1] = countCars[i] + 1;
		} else {
			countCars[i + 1] = countCars[i] - 1;
		}
	}
	for (int i = 0; i < k; i++) {
		Time tempTime;
		scanf("%d:%d:%d", &tempTime.hour, &tempTime.minute, &tempTime.second);
		int queryTime = tempTime.toInt();
		int position = upper_bound(eventTimes.begin(), eventTimes.end(), queryTime) - eventTimes.begin();
		printf("%d\n", countCars[position]);
	}
	int longestTime = -1;
	vector<string> longestCars;
	for (int i = 0; i < carTimes.size(); i++) {
		if (carTimes[i].totalTime > longestTime) {
			longestTime = carTimes[i].totalTime;
			longestCars.clear();
			longestCars.push_back(carTimes[i].plateNumber);
		} else if (carTimes[i].totalTime == longestTime) {
			longestCars.push_back(carTimes[i].plateNumber);
		}
	}
	sort(longestCars.begin(), longestCars.end());
	for (int i = 0; i < longestCars.size(); i++) {
		printf("%s ", longestCars[i].c_str());
	}
	Time ansTime = Time::intToTime(longestTime);
	printf("%02d:%02d:%02d\n", ansTime.hour, ansTime.minute, ansTime.second);
	return 0;
}