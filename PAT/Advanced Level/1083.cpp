#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int n;
	int grade1, grade2;
	vector< pair<int, pair<string, string> > > input;
	vector< pair<int, pair<string, string> > > output;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		string name;
		string id;
		int grade;
		cin >> name >> id >> grade;
		input.push_back(make_pair(-grade, make_pair(name, id)));
	}
	scanf("%d%d", &grade1, &grade2);
	for (int i = 0; i < n; ++i)
	{
		if (input[i].first >= -grade2 && input[i].first <= -grade1)
			output.push_back(input[i]);
	}
	if (!output.size())
	{
		cout << "NONE" << endl;
	}
	else
	{
		sort(output.begin(), output.end());
		for (int i = 0; i < output.size(); ++i)
		{
			cout << output[i].second.first + ' ' + output[i].second.second << endl;
		}
	}
	system("pause");
	return 0;
}
