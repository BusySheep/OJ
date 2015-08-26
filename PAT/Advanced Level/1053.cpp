#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

vector< vector<int> > ans;
vector<int> temp;
int s;
vector<int> tree[100];
int weight[100];

void dfs(int node, int totalWeight)
{
	totalWeight += weight[node];
	temp.push_back(-weight[node]);
	if (tree[node].size() == 0 && totalWeight == s)
	{
		ans.push_back(temp);
	}
	for (int i = 0; i < tree[node].size(); i++)
	{
		dfs(tree[node][i], totalWeight);
	}
	totalWeight -= weight[node];
	temp.pop_back();
}

int main()
{
	int n;
	int m;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; i++)
	{
		int w;
		scanf("%d", &w);
		weight[i] = w;
	}
	for (int i = 0; i < m; i++)
	{
		int id;
		int k;
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++)
		{
			int childId;
			scanf("%d", &childId);
			tree[id].push_back(childId);
		}
	}
	dfs(00, 0);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			printf("%d", -ans[i][j]);
			if (j == ans[i].size() - 1)
			{
				printf("\n");
			}
			else
			{
				printf(" ");
			}
		}
	}
	system("pause");
	return 0;
}
