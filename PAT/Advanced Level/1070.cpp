#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Mooncake
{
	double amounts;
	double price;
	double perPrice;
};

bool cmp(const Mooncake &a, const Mooncake &b)
{
	return a.perPrice > b.perPrice;
}

int main()
{
	int n;
	int d;
	vector<Mooncake> mooncake;
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; ++i)
	{
		double a;
		Mooncake temp;
		scanf("%lf", &a);
		temp.amounts = a;
		temp.price = 0;
		temp.perPrice = 0;
		mooncake.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		double p;
		scanf("%lf", &p);
		mooncake[i].price = p;
		mooncake[i].perPrice = p / mooncake[i].amounts;
	}
	sort(mooncake.begin(), mooncake.end(), cmp);
	int count;
	double maxPrice = 0;
	for (count = 0; d > 0 && count < n; count++)
	{
		if (d >= mooncake[count].amounts)
		{
			maxPrice += mooncake[count].price;
			d -= mooncake[count].amounts;
		}
		else
		{
			maxPrice += d * mooncake[count].perPrice;
			d = 0;
		}
	}
	printf("%.2f\n", maxPrice);
	system("pause");
	return 0;
}
