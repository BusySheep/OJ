#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	const int MAXSIZE = 10001;
	int n;
	int k;
	int m;
	vector<int> temp;
	temp.push_back(0);//total score
	temp.push_back(0);//perfect number
	temp.push_back(0);//uid
	temp.push_back(-1);
	temp.push_back(-1);
	temp.push_back(-1);
	temp.push_back(-1);
	temp.push_back(-1);
	vector< vector<int> > information(MAXSIZE, temp);
	vector< vector<int> > info;
	vector<int> problem;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < k; ++i)
	{
		int score;
		scanf("%d", &score);
		problem.push_back(score);
	}
	for (int i = 0; i < m; ++i)
	{
		int uid;
		int pid;
		int score;
		scanf("%d%d%d", &uid, &pid, &score);
		if (score == -1)
		{
			if (information[uid][pid + 2] < 0)
				information[uid][pid + 2] = 0;
		}
		else
		{
			information[uid][2] = uid;
			if (information[uid][pid + 2] < score)
				information[uid][pid + 2] = score;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (information[i][2] != 0)
		{
			for (int j = 1; j <= k; ++j)
			{
				if (information[i][j + 2] > 0)
				{
					information[i][0] -= information[i][j + 2];
					if (information[i][j + 2] == problem[j - 1])
						information[i][1] --;
				}
			}
			info.push_back(information[i]);
		}
	}
	sort(info.begin(), info.end());
	int finalRank = 1;
	for (int i = 0; i < info.size(); ++i)
	{
		if (i > 0 && info[i][0] != info[i - 1][0])
			finalRank = i + 1;
		printf("%d %05d %d", finalRank, info[i][2], -info[i][0]);
		for (int j = 1; j <= k; ++j)
		{
			if (info[i][j + 2] != -1)
			{
				printf(" %d", info[i][j + 2]);
			}
			else
			{
				printf(" -");
			}
		}
		puts("");
	}
	system("pause");
	return 0;
}
