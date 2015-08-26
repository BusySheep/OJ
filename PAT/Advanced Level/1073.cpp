#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	string number;
	int exp;
	char c;
	cin >> c;
	while (c != 'E')
	{
		number.push_back(c);
		cin >> c;
	}
	cin >> exp;
	if (exp < 0)
	{
		number.erase(number.begin() + 2);
		exp = -exp;
		string zero = "0.";
		if (number.at(0) == '-')
			zero.insert(zero.begin(), '-');
		number.erase(number.begin());
		for (int i = 1; i < exp; ++i)
		{
			zero.push_back('0');
		}
		cout << zero << number << endl;
	}
	else if (exp == 0)
	{
		if (number.at(0) == '+')
			number.erase(number.begin());
		cout << number << endl;
	}
	else
	{
		int flag = 1;
		number.erase(number.begin() + 2);
		if (number.at(0) == '+')
		{
			number.erase(number.begin());
			flag = 0;
		}
		int len = number.size();
		int i;
		for (i = 1; i < flag + 1 + exp; ++i)
		{
			if (i >= len)
				number.push_back('0');
		}
		if (i < len)
			number.insert(number.begin() + i, '.');
		cout << number << endl;
	}
	system("pause");
	return 0;
}
