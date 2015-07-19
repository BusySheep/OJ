#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<int> order;

vector<int> change(vector<int> old)
{
	vector<int> out(54, 0);
	for (int i = 0; i < 54; i++)
	{
		out[order[i] - 1] = old[i];
	}
	return out;
}

int main()
{
	int k;
	vector<int> ini;
	vector<int> ans;
	for (int i = 0; i < 54; i++)
	{
		ini.push_back(i);
		ans.push_back(i);
	}
	scanf("%d", &k);
	for (int i = 0; i < 54; i++)
	{
		int x;
		scanf("%d", &x);
		order.push_back(x);
	}
	for (int i = 0; i < k; i++)
	{
		ans = change(ans);
	}
	int i;
	for (i = 0; i < 53; i++)
	{
		int shape = ans[i] / 13;
		int num = ans[i] % 13 + 1;
		char szShape[6] = "SHCDJ";
		printf("%c%d ", szShape[shape], num);
	}
	int shape = ans[i] / 13;
	int num = ans[i] % 13 + 1;
	char szShape[6] = "SHCDJ";
	printf("%c%d\n", szShape[shape], num);
	system("pause");
	return 0;
}
