#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <queue>
using namespace std;

struct Node
{
	int key;
	Node * child[2];
	Node()
	{
		key = 0;
		child[0] = NULL;
		child[1] = NULL;
	}
};


vector<int> ans;

void buildTree(int n, const int *postOrder, const int *inOrder, Node *root)
{
	int tempKey = postOrder[n - 1];
	root->key = tempKey;
	int offset = 0;
	for (int i = 0; i < n; ++i)
	{
		if (inOrder[i] == tempKey)
		{
			offset = i;
			break;
		}
	}
	if (offset > 0)
	{
		root->child[0] = new Node;
		buildTree(offset, postOrder, inOrder, root->child[0]);
	}
	if (n - offset - 1 > 0)
	{
		root->child[1] = new Node;
		buildTree(n - offset - 1, postOrder + offset, inOrder + offset + 1, root->child[1]);
	}
}

void bfs(Node *root)
{
	queue<Node *> nodeQueue;
	nodeQueue.push(root);
	ans.push_back(root->key);
	while (!nodeQueue.empty())
	{
		Node *head = nodeQueue.front();
		nodeQueue.pop();
		if (head->child[0])
		{
			nodeQueue.push(head->child[0]);
			ans.push_back(head->child[0]->key);
		}
		if (head->child[1])
		{
			nodeQueue.push(head->child[1]);
			ans.push_back(head->child[1]->key);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int postOrder[50];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", postOrder + i);
	}
	int inOrder[50];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", inOrder + i);
	}
	Node *root = new Node;
	buildTree(n, postOrder, inOrder, root);
	bfs(root);
	for (int i = 0; i < ans.size() - 1; ++i)
	{
		printf("%d ", ans[i]);
	}
	printf("%d\n", *(ans.end() - 1));
	system("pause");
	return 0;
}
