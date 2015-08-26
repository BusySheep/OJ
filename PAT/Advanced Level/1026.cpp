#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Time {
	int hour;
	int minute;
	int second;
	void print() {
		printf("%02d:%02d:%02d", hour, minute, second);
	}
	Time() {
		hour = 8;
		minute = 0;
		second = 0;
	}
	Time(int hour, int minute, int second) {
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
};

int operator -(Time a, Time b) {
	return (a.hour * 60 + a.minute) * 60 + a.second - ((b.hour * 60 + b.minute) * 60 + b.second);
}

Time secondToTime(int second) {
	Time result;
	result.hour = 8 + second / 3600;
	result.second = second % 60;
	result.minute = second % 3600 / 60;
	return result;
}

int timeToSecond(Time time) {
	return ((time.hour - 8) * 60 + time.minute) * 60 + time.second;
}

struct Customer {
	int number;
	int arriveTime;
	int lastingTime;
	bool isVIP;
	int serveTime;
};

bool operator <(Customer a, Customer b) {
	return a.arriveTime < b.arriveTime;
}

bool compareServeTime(Customer a, Customer b) {
	return a.serveTime < b.serveTime;
}

struct Table {
	int count;
	bool isUsed;
	int restTime;
	bool isVIP;
	Table() {
		count = 0;
		isUsed = false;
		restTime = 0;
		isVIP = false;
	}
};

const int INF = 1000000000;
const Time beginTime(8, 0, 0);
const Time endTime(21, 0, 0);
const int serveLastingTime = endTime - beginTime;

int main(void) {
	int n;
	vector<Customer> customers;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		Customer customer;
		Time arriveTime;
		int flag;
		scanf("%d:%d:%d %d %d", &arriveTime.hour, &arriveTime.minute, &arriveTime.second, &customer.lastingTime, &flag);
		customer.lastingTime *= 60;
		customer.lastingTime = min(7200, customer.lastingTime);
		customer.isVIP = flag == 1;
		customer.arriveTime = timeToSecond(arriveTime);
		customers.push_back(customer);
	}
	int k;
	int m;
	scanf("%d %d", &k, &m);
	vector<int> vipTables(m, 0);
	vector<Table> tables(k, Table());
	for (int i = 0; i < m; i++) {
		scanf("%d", &vipTables[i]);
		tables[vipTables[i] - 1].isVIP = true;
	}
	sort(customers.begin(), customers.end());
	for (int i = 0; i < n; i++) {
		customers[i].number = i;
	}
	int time = 0;
	queue<Customer> vipQueue;
	queue<Customer> ordinaryQueue;
	for (int i = 0; !vipQueue.empty() || !ordinaryQueue.empty() || i < n;) {
		int stepTime = INF;
		for (int j = 0; j < k; j++) {
			if (tables[j].isUsed == true && tables[j].restTime < stepTime) {
				stepTime = tables[j].restTime;
			}
		}
		if (i < n && customers[i].arriveTime <= time + stepTime) {
			stepTime = customers[i].arriveTime - time;
			if (customers[i].isVIP) {
				vipQueue.push(customers[i]);
				i++;
			}
			else {
				ordinaryQueue.push(customers[i]);
				i++;
			}
		}
		time += stepTime;
		for (int j = 0; j < k; j++) {
			//完成步进
			if (tables[j].isUsed == true) {
				tables[j].restTime -= stepTime;
				if (tables[j].restTime <= 0) {
					tables[j].isUsed = false;
				}
			}
		}
		for (int vipJ = 0; vipJ < m; vipJ++) {
			int j = vipTables[vipJ] - 1;
			//这里只考虑服务VIP队列
			if (tables[j].isUsed == false && !vipQueue.empty()) {
				if (time < serveLastingTime) {
					tables[j].count++;
				}
				tables[j].restTime = vipQueue.front().lastingTime;
				tables[j].isUsed = true;
				int customerNumber = vipQueue.front().number;
				vipQueue.pop();
				customers[customerNumber].serveTime = time;
			}
		}
		for (int j = 0; j < k; j++) {
			//步进之后如果桌子可用
			if (tables[j].isUsed == false && (!vipQueue.empty() || !ordinaryQueue.empty())) {
				if (tables[j].isVIP == false) {//非VIP桌
					//服务两个队列中早到的一人
					if (!vipQueue.empty() && (ordinaryQueue.empty() || vipQueue.front().arriveTime < ordinaryQueue.front().arriveTime)) {
						if (time < serveLastingTime) {
							tables[j].count++;
						}
						tables[j].restTime = vipQueue.front().lastingTime;
						tables[j].isUsed = true;
						int customerNumber = vipQueue.front().number;
						vipQueue.pop();
						customers[customerNumber].serveTime = time;
					}
					else {
						if (time < serveLastingTime) {
							tables[j].count++;
						}
						tables[j].restTime = ordinaryQueue.front().lastingTime;
						tables[j].isUsed = true;
						int customerNumber = ordinaryQueue.front().number;
						ordinaryQueue.pop();
						customers[customerNumber].serveTime = time;
					}
				}
				else {//VIP桌
					//已经处理过VIP队列的服务
					if (time < serveLastingTime) {
						tables[j].count++;
					}
					tables[j].restTime = ordinaryQueue.front().lastingTime;
					tables[j].isUsed = true;
					int customerNumber = ordinaryQueue.front().number;
					ordinaryQueue.pop();
					customers[customerNumber].serveTime = time;

				}
			}
		}
	}
	sort(customers.begin(), customers.end(), compareServeTime);
	for (int i = 0; i < n; i++) {
		if (customers[i].serveTime >= serveLastingTime) {
			continue;
		}
		Time arriveTime = secondToTime(customers[i].arriveTime);
		Time serveTime = secondToTime(customers[i].serveTime);
		arriveTime.print();
		putchar(' ');
		serveTime.print();
		printf(" %d\n", ((serveTime - arriveTime) * 10 / 60 + 5) / 10);
	}
	for (int i = 0; i < k; i++) {
		printf("%d%c", tables[i].count, i == k - 1 ? '\n' : ' ');
	}
	system("pause");
	return 0;
}

