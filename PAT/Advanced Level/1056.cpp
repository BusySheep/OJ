#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> weight;
vector< pair<int, int> > score;

vector<int> findWinner(vector<int> old, int ng)
{
	vector<int> ret;
	for (int i = 0; i < old.size(); i += ng)
	{
		int max = old[i];
		for (int j = 0; j < ng && i + j < old.size(); j++)
		{
			if (weight[old[i + j]] > weight[max])
			{
				max = old[i + j];
			}
		}
		ret.push_back(max);
		score[max].first--;
	}
	return ret;
}

int main()
{
	int np;
	int ng;
	scanf("%d%d", &np, &ng);
	vector<int> order;

	//initial
	for (int i = 0; i < np; i++)
	{
		score.push_back(make_pair(0, i));
	}

	for (int i = 0; i < np; i++)
	{
		int x;
		scanf("%d", &x);
		weight.push_back(x);
	}
	for (int i = 0; i < np; i++)
	{
		int x;
		scanf("%d", &x);
		order.push_back(x);
	}
	vector<int> ans = order;
	while (ans.size() > 1)
	{
		ans = findWinner(ans, ng);
	}

	sort(score.begin(), score.end());
	int rank[1000];
	if (np > 0)
		rank[score[0].second] = 1;
	for (int i = 1; i < np; i++)
	{
		static int r = 1;
		if (score[i].first != score[i - 1].first)
			r = i + 1;
		rank[score[i].second] = r;
	}

	for (int i = 0; i < np; i++)
	{
		printf("%d", rank[i]);
		if (i < np - 1)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
