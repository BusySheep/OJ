#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b)
{
	long long r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main()
{
	int n;
	long long commonMultiple = 1;
	scanf("%lld", &n);
	vector< pair<long long, long long> > number;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		long long numerator;
		long long denominator;
		scanf("%lld/%lld", &numerator, &denominator);
		number.push_back(make_pair(numerator, denominator));
		commonMultiple = commonMultiple * denominator / gcd(commonMultiple, denominator);
		sum += (double)numerator / denominator;
	}
	long long numeratorSum = 0;
	for (int i = 0; i < n; i++)
	{
		number[i].first *= commonMultiple / number[i].second;
		number[i].second = commonMultiple;
		numeratorSum += number[i].first;
	}
	long long integer = numeratorSum / commonMultiple;
	numeratorSum -= integer * commonMultiple;
	long long gen = gcd(numeratorSum, commonMultiple);
	numeratorSum /= gen;
	commonMultiple /= gen;
	numeratorSum = fabs((double)numeratorSum);
	commonMultiple = fabs((double)commonMultiple);
	if (integer != 0 || (integer == 0 && numeratorSum == 0))
	{
		printf("%lld", integer);
		if (numeratorSum != 0)
		{
			printf(" ");
		}
	}
	else if (sum < 0) printf("-");
	if (numeratorSum != 0)
	{
		printf("%lld/%lld", numeratorSum, commonMultiple);
	}
	printf("\n");
	system("pause");
	return 0;
}


