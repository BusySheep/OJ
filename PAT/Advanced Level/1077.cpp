//20:30
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n;
	string str[100];
	scanf("%d", &n);
	getchar();
	int minLength = 100000;
	for (size_t i = 0; i < n; i++)
	{
		char temp[257];
		gets(temp);
		str[i] = temp;
		if (str[i].length() < minLength)
		{
			minLength = str[i].length();
		}
	}
	string suffix = "";
	for (int i = 1; i <= minLength; i++)
	{
		char c = str[0].at(str[0].length() - i);
		int j;
		for (j = 1; j < n; j++)
		{
			if (str[j].at(str[j].length() - i) != c)
			{
				break;
			}
		}
		if (j < n)
		{
			break;
		}
		else
		{
			suffix += c;
		}
	}
	reverse(suffix.begin(), suffix.end());
	if (suffix == "")
	{
		cout << "nai" << endl;
	}
	else
	{
		cout << suffix << endl;
	}
	system("pause");
	return 0;
}
//20:49
