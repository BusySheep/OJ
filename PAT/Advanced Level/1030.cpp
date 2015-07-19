#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <climits>
using namespace std;

class Way
{
public:
	Way(int a, int b, int c) :city(a), distance(b), cost(c){}
	int city;
	int distance;
	int cost;
};

int main()
{
	const int MAXSIZE = 500;
	int n;
	int m;
	int s;
	int d;
	vector<Way> gr[MAXSIZE];
	vector<bool> flag(MAXSIZE, false);
	vector<int> minDistance(MAXSIZE, INT_MAX);
	vector<int> minCost(MAXSIZE, INT_MAX);
	vector<int> preCity(MAXSIZE, -1);
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for (int i = 0; i < m; ++i)
	{
		int x, y, distance, cost;
		scanf("%d%d%d%d", &x, &y, &distance, &cost);
		gr[x].push_back(*(new Way(y, distance, cost)));
		gr[y].push_back(*(new Way(x, distance, cost)));
	}
	queue<int> nodeQueue;
	nodeQueue.push(s);
	flag[s] = true;
	minDistance[s] = 0;
	minCost[s] = 0;
	while (!nodeQueue.empty())
	{
		int head = nodeQueue.front();
		nodeQueue.pop();
		flag[head] = false;
		for (int i = 0; i < gr[head].size(); ++i)
		{
			int distance = gr[head][i].distance;
			int cost = gr[head][i].cost;
			int adjCity = gr[head][i].city;
			if (minDistance[head] + distance < minDistance[adjCity])
			{
				minCost[adjCity] = minCost[head] + cost;
				preCity[adjCity] = head;
				minDistance[adjCity] = minDistance[head] + distance;
				if (!flag[adjCity])
				{
					nodeQueue.push(adjCity);
					flag[adjCity] = true;
				}
			}
			else if (minDistance[head] + distance == minDistance[adjCity])
			{
				if (minCost[adjCity] > minCost[head] + cost)
				{
					minCost[adjCity] = minCost[head] + cost;
					preCity[adjCity] = head;
					if (!flag[adjCity])
					{
						nodeQueue.push(adjCity);
						flag[adjCity] = true;
					}
				}
			}
		}
	}
	vector<int> shortestPath;
	int temp = d;
	while (temp != s)
	{
		shortestPath.insert(shortestPath.begin(), temp);
		temp = preCity[temp];
	}
	printf("%d ", s);
	for (int i = 0; i < shortestPath.size(); ++i)
	{
		printf("%d ", shortestPath[i]);
	}
	printf("%d %d\n", minDistance[d], minCost[d]);
	system("pause");
	return 0;
}
