#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	int n;
	int k;
	const int endTime = (17 - 8) * 60 * 60;
	scanf("%d%d", &n, &k);
	vector< pair<int, int> > people;
	const vector<int> empty(k, -1);
	vector<int> windows(k, -1);
	for (int i = 0; i < n; i++)
	{
		int hour, minu, sec;
		int proTime;
		scanf("%d:%d:%d %d", &hour, &minu, &sec, &proTime);
		int arrivedTime = ((hour - 8) * 60 + minu) * 60 + sec;
		proTime *= 60;
		proTime = min(proTime, 3600);
		if (arrivedTime <= endTime)
			people.push_back(make_pair(arrivedTime, proTime));
	}
	vector<int> doneTime(people.size(), 0);
	sort(people.begin(), people.end());
	vector< pair<int, int> > oriPeopleData = people;
	for (int i = 0; i < people.size(); i++)
	{
		if (people[i].first < 0)
			people[i].first = 0;
	}
	int second = 0;
	int customerId = 0;
	while (true)
	{
		if (customerId >= people.size() && windows == empty) break;
		int minSec = INT_MAX;
		for (int i = 0; i < k; i++)
		{
			if (windows[i] == -1 && customerId < people.size() && second >= people[customerId].first)
			{
				windows[i] = customerId++;
			}
			if (windows[i] != -1 && people[windows[i]].second < minSec)
			{
				minSec = people[windows[i]].second;
			}
		}
		if (customerId < people.size() && people[customerId].first - second > 0)
		{
			minSec = min(minSec, people[customerId].first - second);
		}
		second += minSec;
		for (int i = 0; i < k; i++)
		{
			if (windows[i] != -1)
			{
				int id = windows[i];
				people[id].second -= minSec;
				if (people[id].second == 0)
				{
					windows[i] = -1;
					doneTime[id] = second;
				}
			}
		}
	}
	int totalWaitTime = 0;
	for (int i = 0; i < people.size(); i++)
	{
		totalWaitTime += doneTime[i] - oriPeopleData[i].second - oriPeopleData[i].first;
	}
	double aver = (double)totalWaitTime / people.size() / 60;
	printf("%.1f\n", aver);
	system("pause");
	return 0;
}
