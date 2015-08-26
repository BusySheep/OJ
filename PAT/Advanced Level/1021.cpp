#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAXSIZE = 10001;

vector<bool> visited(MAXSIZE, false);
vector<int> nodes[MAXSIZE];

int dfs(int now, int depth)
{
	visited[now] = true;
	int dep = depth;
	for (int i = 0; i < nodes[now].size(); ++i)
	{
		if (!visited[nodes[now][i]])
		{
			int temp = dfs(nodes[now][i], depth + 1);
			if (temp > dep)
				dep = temp;
		}
	}
	return dep;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		nodes[x].push_back(y);
		nodes[y].push_back(x);
	}
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			count++;
			dfs(i, 0);
		}
	}
	if (count != 1)
	{
		printf("Error: %d components\n", count);
	}
	else
	{
		vector<int> ans;
		int maxDepth = 0;
		for (int i = 1; i <= n; ++i)
		{
			fill_n(visited.begin(), visited.size(), false);
			int temp = dfs(i, 0);
			if (temp > maxDepth)
			{
				ans.clear();
				maxDepth = temp;
				ans.push_back(i);
			}
			else if (temp == maxDepth)
			{
				ans.push_back(i);
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); ++i)
		{
			printf("%d\n", ans[i]);
		}
	}
	system("pause");
	return 0;
}
