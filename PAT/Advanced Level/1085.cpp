//12:22
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n;
	long long p;
	scanf("%d%lld", &n, &p);
	vector<long long> number;
	for (int i = 0; i < n; i++)
	{
		long long x;
		scanf("%lld", &x);
		number.push_back(x);
	}
	sort(number.begin(), number.end());
	int maxLength = 0;
	for (int i = 0; i < n; i++)
	{
		long long px = number[i] * p;
		vector<long long>::iterator posi = upper_bound(number.begin(), number.end(), px);
		int length = posi - number.begin() - i;
		if (length > maxLength)
		{
			maxLength = length;
		}
	}
	printf("%d\n", maxLength);
	system("pause");
	return 0;
}
//12:31
