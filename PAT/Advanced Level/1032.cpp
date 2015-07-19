#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int nodes[100000];
	int address_next[100000];
	int n;
	int head1;
	int head2;
	scanf("%d %d %d", &head1, &head2, &n);
	memset(nodes, 0, sizeof(nodes));
	memset(address_next, 0, sizeof(address_next));
	for (int i = 0; i < n; ++i)
	{
		int address;
		int next;
		scanf("%d %*c %d", &address, &next);
		address_next[address] = next;
	}
	int address1 = head1;
	int address2 = head2;
	if (head1 == head2)
	{
		printf("%05d\n", head1);
		system("pause");
		return 0;
	}
	while (address1 != -1)
	{
		address1 = address_next[address1];
		if (address1 != -1)
			nodes[address1]++;
	}
	bool flag = false;
	while (address2 != -1)
	{
		address2 = address_next[address2];
		if (address2 != -1)
			nodes[address2]++;
		if (nodes[address2] == 2)
		{
			printf("%05d\n", address2);
			flag = true;
			break;
		}
	}
	if (flag == false)
		printf("-1\n");
	system("pause");
	return 0;
}
