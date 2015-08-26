#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int m;
	scanf("%d%d", &n, &m);
	vector<int> value;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		value.push_back(x);
	}
	vector< pair<int, int> > ans;
	int minSum = 1000000000;
	int sum = 0;
	int i = 0, j;
	for (j = 0; j < n; j++)
	{
		sum += value[j];
		if (sum >= m)
		{
			if (sum < minSum)
			{
				ans.clear();
				ans.push_back(make_pair(i, j));
				minSum = sum;
			}
			else if (sum == minSum)
			{
				ans.push_back(make_pair(i, j));
			}
			break;
		}
	}
	for (i = 1; i < n; i++)
	{
		sum -= value[i - 1];
		while (sum >= m)
		{
			sum -= value[j--];
		}
		while (sum < m)
		{
			if (j == n - 1) break;
			sum += value[++j];
		}
		if (j == n - 1 && sum < m) break;
		if (sum < minSum)
		{
			ans.clear();
			ans.push_back(make_pair(i, j));
			minSum = sum;
		}
		else if (sum == minSum)
		{
			ans.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d-%d\n", ans[i].first + 1, ans[i].second + 1);
	}
	system("pause");
	return 0;
}
