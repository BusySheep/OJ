//17:33
#include <cstdio>
#include <algorithm>
using namespace std;

int tree[1001];
int cnt = 0;
int number[1000];
int n;

void inOrder(int root)
{
	if (root * 2 <= n)
	{
		inOrder(root * 2);
	}
	tree[root] = number[cnt++];
	if (root * 2 + 1 <= n)
	{
		inOrder(root * 2 + 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", number + i);
	}
	sort(number, number + n);
	inOrder(1);
	for (size_t i = 1; i <= n; i++)
	{
		printf("%d", tree[i]);
		if (i == n) printf("\n");
		else printf(" ");
	}
	system("pause");
	return 0;
}
//17:52
