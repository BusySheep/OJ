#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int k;
	int ageNumber[201];
	fill(ageNumber, ageNumber + 201, 0);
	vector< pair<int, pair<int, string> > > person;
	vector< pair<int, pair<int, string> > > rank;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		string name;
		char szName[10];
		int age;
		int worth;
		scanf("%s %d %d", szName, &age, &worth);
		name = szName;
		person.push_back(make_pair(-worth, make_pair(age, name)));
	}
	sort(person.begin(), person.end());
	for (int i = 0; i < n; i++)
	{
		int age = person[i].second.first;
		if (ageNumber[age] <= 100)
		{
			ageNumber[age]++;
			rank.push_back(person[i]);
		}
	}
	for (int i = 0; i < k; i++)
	{
		int m;
		int ageMin;
		int ageMax;
		int count = 0;
		scanf("%d%d%d", &m, &ageMin, &ageMax);
		printf("Case #%d:\n", i + 1);
		for (int j = 0; j < rank.size(); j++)
		{
			int age = rank[j].second.first;
			if (count < m && age >= ageMin && age <= ageMax)
			{
				count++;
				printf("%s %d %d\n", rank[j].second.second.c_str(), rank[j].second.first, -rank[j].first);
			}
			if (count >= m)
			{
				break;
			}
		}
		if (count == 0)
		{
			printf("None\n");
		}
	}
	system("pause");
	return 0;
}
