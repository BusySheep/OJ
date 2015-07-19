#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int n;
	int k;
	vector<string> course[2501];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		string student;
		int c;
		cin >> student >> c;
		for (int j = 0; j < c; j++)
		{
			int courseId;
			scanf("%d", &courseId);
			course[courseId].push_back(student);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		sort(course[i].begin(), course[i].end());
		printf("%d %d\n", i, course[i].size());
		for (int j = 0; j < course[i].size(); j++)
		{
			printf("%s\n", course[i][j].c_str());
		}
	}
	system("pause");
	return 0;
}
