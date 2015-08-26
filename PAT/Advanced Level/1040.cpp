#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool isSym(char * str, int length)
{
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		if (str[i] != str[j])
			return false;
	}
	return true;
}

int main()
{
	int i;
	int j;
	char str[1001];
	gets(str);
	int len = strlen(str);
	int maxlen = 1;
	if (str[0] == 0)
		maxlen = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = len - 1; j > i; j--)
		{
			if (isSym(str + i, j - i + 1))
			{
				maxlen = max(maxlen, j - i + 1);
				break;
			}
		}
	}
	printf("%d\n", maxlen);
	system("pause");
	return 0;
}
