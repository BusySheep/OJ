#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int MAXSIZE = 2005;
double gang[MAXSIZE][MAXSIZE];
bool visited[MAXSIZE];
double totalTime[MAXSIZE];

int num = 0;

int headId;
int gangMemberNumber = 0;
double totalWeight = 0;

void findHeadId(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;

	while (!q.empty())
	{
		int h = q.front();
		q.pop();
		gangMemberNumber++;
		if (totalTime[h] > totalTime[headId])
			headId = h;
		for (int i = 0; i < num; ++i)
		{
			totalWeight += gang[h][i];
			if (!visited[i] && gang[h][i] != 0)
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	int n;
	double k;
	scanf("%d %lf", &n, &k);
	map<string, int> id;
	map<int, string> r_id;
	for (int i = 0; i < n; ++i)
	{
		string name1;
		string name2;
		double time;
		cin >> name1 >> name2 >> time;
		if (id.count(name1) == 0)
		{
			id[name1] = num;
			r_id[num] = name1;
			num++;
		}
		if (id.count(name2) == 0)
		{
			id[name2] = num;
			r_id[num] = name2;
			num++;
		}
		int num1 = id[name1];
		int num2 = id[name2];
		gang[num1][num2] += time;
		gang[num2][num1] += time;
		totalTime[num1] += time;
		totalTime[num2] += time;
	}
	vector<pair<string, double> > heads;
	for (int i = 0; i < num; ++i)
	{
		if (!visited[i])
		{
			headId = i;
			gangMemberNumber = 0;
			totalWeight = 0;
			findHeadId(i);
			string headName = r_id[headId];
			if (gangMemberNumber > 2 && totalWeight > 2 * k)//totalWeight计算时每条路径算了两遍
			{
				heads.push_back(make_pair(headName, gangMemberNumber));
			}
		}
	}
	sort(heads.begin(), heads.end());
	printf("%d\n", heads.size());
	for (int i = 0; i < heads.size(); ++i)
	{
		printf("%s %.0f\n", heads[i].first.c_str(), heads[i].second);
	}
	system("pause");
	return 0;
}
