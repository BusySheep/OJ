//17:11
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n;
	set<int> s[50];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		for (size_t j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			s[i].insert(x);
		}
	}
	int k;
	scanf("%d", &k);
	for (size_t i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		int nc = 0, nt;
		for (set<int>::iterator ita = s[a].begin(), itb = s[b].begin(); ita != s[a].end() && itb != s[b].end();)
		{
			if (*ita < *itb)
			{
				ita++;
			}
			else if (*ita > *itb)
			{
				itb++;
			}
			else
			{
				nc++;
				ita++;
				itb++;
			}
		}
		nt = s[a].size() + s[b].size() - nc;
		double similarity = (double)nc / nt;
		similarity *= 100;
		printf("%.1f%%\n", similarity);
	}
	system("pause");
	return 0;
}
//17:32
