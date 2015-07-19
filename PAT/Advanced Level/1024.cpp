#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int bigNumAdd_equalNumberOfBits(const char *a, const char *b, char *result)
{
	int lenA = strlen(a);
	int lenB = strlen(b);
	int carry = 0;
	for (int i = lenA - 1; i >= 0; --i)
	{
		result[i] = carry + a[i] + b[i] - '0';
		carry = (result[i] - '0') / 10;
		result[i] -= carry * 10;
	}
	result[lenA] = 0;
	return carry;
}

bool isPalin(char * n)
{
	char r_n[100];
	int len = strlen(n);
	strcpy(r_n, n);
	reverse(r_n, r_n + len);
	return strcmp(r_n, n) == 0;
}

int main()
{
	char n[100];
	char r_n[100];
	char temp[100];
	int k;
	scanf("%s %d", n, &k);
	int i = 0;
	if (!isPalin(n))
	{
		for (; i < k; ++i)
		{
			int len = strlen(n);
			strcpy(r_n, n);
			reverse(r_n, r_n + len);
			temp[0] = '0' + bigNumAdd_equalNumberOfBits(n, r_n, temp + 1);
			if (temp[0] == '0')
				strcpy(temp, temp + 1);
			strcpy(n, temp);
			if (isPalin(n))
			{
				++i;
				break;
			}
		}
	}
	printf("%s\n%d\n", n, i);
	system("pause");
	return 0;
}
