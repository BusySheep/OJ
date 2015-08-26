//20:49
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

bool isPrime(int n)
{
	int sq = sqrt(n);
	if (n == 1) return false;
	for (int i = 2; i <= sq; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int findNextPrimeNumber(int n)
{
	int i;
	for (i = n;; i++)
	{
		if (isPrime(i))
			break;
	}
	return i;
}

int main()
{
	int mSize;
	int n;
	scanf("%d%d", &mSize, &n);
	int tSize = findNextPrimeNumber(mSize);
	int hash[20000];
	fill(hash, hash + 20000, 0);
	int position[10000];
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		int pos = x % tSize;
		int posi = pos;
		long long j;
		for (j = 1; j < 100000 && hash[posi] != 0; j++)
		{
			posi = ((long long)j * j + pos) % tSize;
		}
		if (j >= 100000)
		{
			position[i] = -1;
		}
		else
		{
			position[i] = posi;
			hash[posi] = x;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (position[i] >= 0)
		{
			printf("%d", position[i]);
		}
		else
		{
			printf("-");
		}
		if (i != n - 1)
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
//21:16
//17·Ö
//21:26
//22·Ö
//22:44
//AC
