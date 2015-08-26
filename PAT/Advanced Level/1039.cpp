#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int k;
	vector<int> query[200000];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++)
	{
		int courseId;
		int studentNumber;
		scanf("%d %d", &courseId, &studentNumber);
		for (int j = 0; j < studentNumber; j++)
		{
			char tempName[5];
			scanf("%s", tempName);
			int name = (tempName[0] - 'A') * 26 * 26 * 10 + (tempName[1] - 'A') * 26 * 10 + (tempName[2] - 'A') * 10 + (tempName[3] - '0');
			query[name].push_back(courseId);
		}
	}
	for (int i = 0; i < n; i++)
	{
		char tempName[5];
		scanf("%s", tempName);
		int name = (tempName[0] - 'A') * 26 * 26 * 10 + (tempName[1] - 'A') * 26 * 10 + (tempName[2] - 'A') * 10 + (tempName[3] - '0');
		vector<int> temp = query[name];
		sort(temp.begin(), temp.end());
		printf("%s %d", tempName, temp.size());
		for (int j = 0; j < temp.size(); j++)
		{
			printf(" %d", temp[j]);
		}
		puts("");
	}
	system("pause");
	return 0;
}
