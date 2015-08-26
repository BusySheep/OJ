//21:31
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	double p;
	double r;
	scanf("%d%lf%lf", &n, &p, &r);
	vector< vector<int> > chain(n, vector<int>());
	vector<int> product(n, 0);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			chain[i].push_back(x);
		}
		if (k == 0)
		{
			int x;
			scanf("%d", &x);
			product[i] = x;
		}
	}
	double total = 0;
	queue< pair<int, double> > q;
	q.push(make_pair(0, p));
	while (!q.empty())
	{
		int id = q.front().first;
		double price = q.front().second;
		q.pop();
		if (chain[id].size() == 0)
		{
			total += product[id] * price;
		}
		else
		{
			for (int i = 0; i < chain[id].size(); i++)
			{
				q.push(make_pair(chain[id][i], price * (1 + r / 100)));
			}
		}
	}
	printf("%.1f\n", total);
	system("pause");
	return 0;
}
//21:58

