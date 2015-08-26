#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> citys[1001];
int importantCitys[1001];
bool visited[1001];
int n;
int m;
int k;

void dfs(int city, int index)
{
	int i;
	visited[city] = true;
	for (i = 0; i < citys[city].size(); ++i)
	{
		if (!visited[citys[city][i]] && citys[city][i] != importantCitys[index])
			dfs(citys[city][i], index);
	}
}

int main()
{
	int i;
	int x, y;
	int count = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		citys[x].push_back(y);
		citys[y].push_back(x);
	}
	for (i = 0; i < k; i++)
	{
		scanf("%d", importantCitys + i);
	}
	for (i = 0; i < k; i++)
	{
		count = 0;
		memset(visited, false, (n + 1) * sizeof(bool));
		int j;
		for (j = 1; j <= n; j++)
		{
			if (visited[j] == false && j != importantCitys[i])
			{
				dfs(j, i);
				count++;
			}
		}
		cout << count - 1 << endl;
	}
	system("pause");
	return 0;
}
