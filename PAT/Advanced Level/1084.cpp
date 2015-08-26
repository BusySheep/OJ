//12:16
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	char temp[81];
	string old;
	string typed;
	vector<bool> flag(256, false);
	gets(temp);
	old = temp;
	gets(temp);
	typed = temp;
	for (int i = 0; i < old.length(); i++)
	{
		if (old[i] >= 'a' && old[i] <= 'z')
			old[i] += 'A' - 'a';
	}
	for (int i = 0; i < typed.length(); i++)
	{
		if (typed[i] >= 'a' && typed[i] <= 'z')
			typed[i] += 'A' - 'a';
	}
	for (int i = 0, j = 0; i < old.length() && j < typed.length(); i++, j++)
	{
		while (old[i] != typed[j])
		{
			char c = old[i++];
			if (flag[c] == false)
			{
				flag[c] = true;
				printf("%c", c);
			}
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
//12:22
