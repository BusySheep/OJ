#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	int n, m, l;
	int i;
	vector<int> favo;
	int match[200];
	vector<int> a;
	int f[10000];
	cin >> n;
	cin >> m;
	memset(match, 0, n * sizeof(int));
	//0代表一种颜色应该被删除
	int x;
	for (i = 0; i < m; i++)
	{
		cin >> x;
		favo.push_back(x);
		match[x] = i + 1;
	}
	cin >> l;
	for (i = 0; i < l; i++)
	{
		cin >> x;
		x = match[x];
		if (x != 0)	a.push_back(x);
	}
	for (i = 0; i < a.size(); i++)
	{
		f[i] = 1;
	}
	int j;
	int ans = 0;
	for (i = 0; i < a.size(); i++)
	{
		for (j = 0; j < i; j++)
		{
			if (a[i] >= a[j])
				f[i] = max(f[i], f[j] + 1);
		}
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	system("pause");
	return 0;
}
