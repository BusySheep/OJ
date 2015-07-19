#include <cstdio>
#include <map>
using namespace std;

int main()
{
	int m;
	int n;
	map<int, int> image;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int x;
			scanf("%d", &x);
			image[x]++;
		}
	}
	int ans = image.begin()->first;
	for (map<int, int>::iterator it = image.begin(); it != image.end(); ++it)
	{
		if (image[ans] < it->second)
			ans = it->first;
	}
	printf("%d\n", ans);
	system("pause");
	return 0;
}
