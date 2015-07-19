//16:50
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	int l;
	int h;
	scanf("%d%d%d", &n, &l, &h);
	vector<vector <int> > people;
	for (int i = 0; i < n; i++)
	{
		int id;
		int totalGrade;
		int virtueGrade;
		int talentGrade;
		int kind = 4;
		scanf("%d%d%d", &id, &virtueGrade, &talentGrade);
		totalGrade = virtueGrade + talentGrade;
		vector<int> temp;
		if (virtueGrade < l || talentGrade < l)
		{
			continue;
		}
		if (virtueGrade >= h && talentGrade >= h)
		{
			kind = 1;
		}
		else if (virtueGrade >= h)
		{
			kind = 2;
		}
		else if (virtueGrade >= talentGrade)
		{
			kind = 3;
		}
		else
		{
			kind = 4;
		}
		temp.push_back(kind);
		temp.push_back(-totalGrade);
		temp.push_back(-virtueGrade);
		temp.push_back(-talentGrade);
		temp.push_back(id);
		people.push_back(temp);
	}
	printf("%d\n", people.size());
	sort(people.begin(), people.end());
	for (int i = 0; i < people.size(); i++)
	{
		printf("%08d %d %d\n", people[i][4], -people[i][2], -people[i][3]);
	}
	system("pause");
	return 0;
}
//17:11
