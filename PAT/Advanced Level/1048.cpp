#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int m;
	scanf("%d%d", &n, &m);
	vector<int> coins;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		coins.push_back(x);
	}
	sort(coins.begin(), coins.end());
	if (n == 1)
	{
		printf("No Solution\n");
		system("pause");
		return 0;
	}
	int i, j;
	for (i = 0, j = 1; coins[i] + coins[j] != m && i < j; i++)
	{
		while (coins[i] + coins[j] > m && i < j - 1)
		{
			j--;
		}
		while (coins[i] + coins[j] < m && j < n - 1)
		{
			j++;
		}
		if (coins[i] + coins[j] == m)
		{
			printf("%d %d\n", coins[i], coins[j]);
			system("pause");
			return 0;
		}
	}
	if (coins[i] + coins[j] == m)
	{
		printf("%d %d\n", coins[i], coins[j]);
	}
	else
	{
		printf("No Solution\n");
	}
	system("pause");
	return 0;
}
