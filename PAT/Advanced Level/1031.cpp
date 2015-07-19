#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string input;
	cin >> input;
	int len = input.length();
	int n1 = len / 3;
	if (len % 3 == 0)
		n1--;
	int n2 = len - n1 - n1;
	int n4 = n2 - 2;
	int i;
	string output = "";
	for (i = 0; i < n1; i++)
	{
		output = "";
		output += input.at(i);
		int j;
		for (j = 0; j < n4; j++)
		{
			output += ' ';
		}
		output += input.at(len - 1 - i);
		cout << output << endl;
	}
	for (i = n1; i < n1 + n2; i++)
	{
		cout << input.at(i);
	}
	cout << endl;
	system("pause");
	return 0;
}
