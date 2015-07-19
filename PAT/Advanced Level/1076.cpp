#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAXSIZE = 1001;

int main()
{
	vector<int> graph[MAXSIZE];
	int n;
	int l;
	int m;
	int x;
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &x);
			graph[x].push_back(i);
		}
	}
	int k;
	int query[MAXSIZE];
	int ans;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		ans = -1;//×Ô¼º²»Ëã
		scanf("%d", query + i);
		queue< pair<int, int> > q;
		bool visited[MAXSIZE];
		memset(visited, false, sizeof(visited));
		q.push(make_pair(query[i], 0));
		visited[query[i]] = true;
		while (!q.empty())
		{
			int head = q.front().first;
			int nowLevel = q.front().second;
			q.pop();
			ans++;
			if (nowLevel < l)
			{
				for (int j = 0; j < graph[head].size(); j++)
				{
					if (!visited[graph[head][j]])
					{
						q.push(make_pair(graph[head][j], nowLevel + 1));
						visited[graph[head][j]] = true;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}
