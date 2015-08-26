//21:58
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n;
	int m;
	int k;
	scanf("%d%d%d", &n, &m, &k);
	vector<int> school(m, 0);
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		school[i] = x;
	}
	vector< vector<int> > student;
	for (int i = 0; i < n; i++)
	{
		vector<int> temp;
		int ge, gi;
		scanf("%d%d", &ge, &gi);
		int finalScore = ge + gi;
		temp.push_back(-finalScore);
		temp.push_back(-ge);
		temp.push_back(-gi);
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			temp.push_back(x);
		}
		temp.push_back(i);//student's ID
		student.push_back(temp);
	}
	sort(student.begin(), student.end());
	vector< vector<int> > admit(m, vector<int>());
	for (int i = 0; i < n; i++)
	{
		vector< pair<int, int> > temp;
		for (int ki = 0; ki < k; ki++)
		{
			int schoolId = student[i][3 + ki];
			if (school[schoolId] > 0)
			{
				temp.push_back(make_pair(i, schoolId));
				break;
			}
		}
		for (; i + 1 < n && student[i][0] == student[i + 1][0] && student[i][1] == student[i + 1][1]; i++)
		{
			for (int ki = 0; ki < k; ki++)
			{
				int schoolId = student[i + 1][3 + ki];
				if (school[schoolId] > 0)
				{
					temp.push_back(make_pair(i + 1, schoolId));
					break;
				}
			}
		}
		for (int j = 0; j < temp.size(); j++)
		{
			int studentId = temp[j].first;
			studentId = student[studentId][3 + k];
			int schoolId = temp[j].second;
			school[schoolId]--;
			admit[schoolId].push_back(studentId);
		}
	}
	for (int i = 0; i < admit.size(); i++)
	{
		sort(admit[i].begin(), admit[i].end());
		for (int j = 0; j < admit[i].size(); j++)
		{
			printf("%d", admit[i][j]);
			if (j != admit[i].size() - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
//22:39

