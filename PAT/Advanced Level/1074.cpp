#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	int k;
	int head;
	cin >> head >> n >> k;
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
	while (data[address].second != -1)
	{
		list.push_back(make_pair(address, data[address].first));
		address = data[address].second;
	}
	list.push_back(make_pair(address, data[address].first));
	for (int i = 1; i * k <= list.size(); ++i)
	{
		reverse(list.begin() + (i - 1) * k, list.begin() + i * k);
	}
	int i;
	for (i = 0; i < list.size() - 1; ++i)
	{
		printf("%05d %d %05d\n", list[i].first, list[i].second, list[i + 1].first);
	}
	printf("%05d %d -1\n", list[i].first, list[i].second);
	system("pause");
	return 0;
}
