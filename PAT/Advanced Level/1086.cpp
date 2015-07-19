//12:31
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

vector<int> inOrder;
vector<int> preOrder;
int num = 0;

void postOrder(int l, int r)
{
	if (l >= r) return;
	int node = preOrder[num++];
	int pos = 0;
	for (int i = l; i < r; i++)
	{
		if (inOrder[i] == node)
		{
			pos = i;
			break;
		}
	}
	postOrder(l, pos);
	postOrder(pos + 1, r);
	printf("%d", node);
	if (node != preOrder[0])
		printf(" ");
	else
		printf("\n");
}

int main()
{
	int n;
	cin >> n;
	int number = n * 2;
	stack<int> s;
	for (int i = 0; i < number; i++)
	{
		string command;
		int x = 0;
		cin >> command;
		if (command == "Push")
		{
			cin >> x;
			preOrder.push_back(x);
			s.push(x);
		}
		else
		{
			inOrder.push_back(s.top());
			s.pop();
		}
	}
	postOrder(0, n);
	system("pause");
	return 0;
}
//12:49
