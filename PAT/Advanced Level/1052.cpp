#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	int n;
	int head;
	cin >> n >> head;
	pair<int, int> data[100001];
	vector< pair<int, int> > list;
	for (int i = 0; i < n; ++i)
	{
		int address;
		cin >> address;
		int x;
		int next;
		cin >> x >> next;
		data[address] = make_pair(x, next);
	}
	int address = head;
	if (head == -1)
	{
		printf("0 -1\n");
		return 0;
	}
	while (data[address].second != -1)
	{
		list.push_back(make_pair(address, data[address].first));
		address = data[address].second;
	}
	list.push_back(make_pair(address, data[address].first));
	sort(list.begin(), list.end(), cmp);
	int i = 0;
	printf("%d %05d\n", list.size(), list[i].first);
	for (i = 0; i < list.size() - 1; ++i)
	{
		printf("%05d %d %05d\n", list[i].first, list[i].second, list[i + 1].first);
	}
	printf("%05d %d -1\n", list[i].first, list[i].second);
	system("pause");
	return 0;
}
