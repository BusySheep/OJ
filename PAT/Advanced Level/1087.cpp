//12:49
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int transform(const char *temp)
{
	return ((temp[0] - 'A') * 26 + temp[1] - 'A') * 26 + temp[2] - 'A';
}

int main()
{
	const int INF = 1000000000;
	const int MAXSIZE = 26 * 26 * 26;

	vector<bool> flag(MAXSIZE, false);
	vector<int> happ(MAXSIZE, 0);
	vector< vector< pair<int, int> > > graph(MAXSIZE, vector< pair<int, int> >());
	vector<int> minCost(MAXSIZE, INF);
	vector<bool> visited(MAXSIZE, false);
	vector<int> path(MAXSIZE, 0);
	vector<int> maxHapp(MAXSIZE, 0);
	vector<int> step(MAXSIZE, 0);
	vector<int> pre(MAXSIZE, -1);

	char temp[4] = "ROM";
	int dest = transform(temp);
	int n;
	int k;
	int start;
	scanf("%d%d%s", &n, &k, temp);
	getchar();
	start = transform(temp);
	flag[start] = true;

	for (int i = 1; i < n; i++)
	{
		int x;
		scanf("%s%d", temp, &x);
		getchar();
		int city = transform(temp);
		flag[city] = true;
		happ[city] = x;
	}
	for (int i = 0; i < k; i++)
	{
		int cost;
		scanf("%s", temp);
		int city1 = transform(temp);
		scanf("%s", temp);
		int city2 = transform(temp);
		scanf("%d", &cost);
		getchar();
		graph[city1].push_back(make_pair(city2, cost));
		graph[city2].push_back(make_pair(city1, cost));
	}

	path[start] = 1;
	minCost[start] = 0;
	for (int i = 0; i < n; i++)
	{
		int best_j = -1;
		for (int j = 0; j < MAXSIZE; j++)
		{
			if (flag[j] && !visited[j] && (best_j < 0 || minCost[j] < minCost[best_j]))
				best_j = j;
		}
		visited[best_j] = true;
		for (int j = 0; j < graph[best_j].size(); j++)
		{
			int city = graph[best_j][j].first;
			int cost = graph[best_j][j].second;
			if (!visited[city] && minCost[city] > minCost[best_j] + cost)
			{
				minCost[city] = minCost[best_j] + cost;
				path[city] = path[best_j];
				maxHapp[city] = maxHapp[best_j] + happ[city];
				step[city] = step[best_j] + 1;
				pre[city] = best_j;
			}
			else if (!visited[city] && minCost[city] == minCost[best_j] + cost)
			{
				path[city] += path[best_j];
				if (maxHapp[city] < maxHapp[best_j] + happ[city])
				{
					maxHapp[city] = maxHapp[best_j] + happ[city];
					step[city] = step[best_j] + 1;
					pre[city] = best_j;
				}
				else if (maxHapp[city] == maxHapp[best_j] + happ[city])
				{
					if (step[city] > step[best_j] + 1)
					{
						step[city] = step[best_j] + 1;
						pre[city] = best_j;
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n", path[dest], minCost[dest], maxHapp[dest], maxHapp[dest] / step[dest]);
	vector<string> ans;
	int tempCity = dest;
	while (tempCity != -1)
	{
		int t = tempCity;
		temp[2] = t % 26 + 'A';
		t /= 26;
		temp[1] = t % 26 + 'A';
		t /= 26;
		temp[0] = t + 'A';
		temp[3] = 0;
		string tem = temp;
		ans.push_back(tem);
		tempCity = pre[tempCity];
	}
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		printf("%s", ans[i].c_str());
		if (i != 0)
			printf("->");
	}
	printf("\n");
	system("pause");
	return 0;
}
//13:28
