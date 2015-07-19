#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int tempDistance = 0;
	int n;
	vector<int> cycle;
	scanf("%d", &n);
	cycle.push_back(0);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		tempDistance += x;
		cycle.push_back(tempDistance);
	}
	for (int i = 1; i < n; ++i)
	{
		cycle.push_back(cycle[i] + cycle[n]);
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		int l, r;
		scanf("%d %d", &l, &r);

		l--;
		r--;
		
		if (l > r)
			swap(l, r);
		int ans1, ans2;
		ans1 = cycle[r] - cycle[l];
		ans2 = cycle[l + n] - cycle[r];
		printf("%d\n", min(ans1, ans2));
	}
	system("pause");
	return 0;
}
