#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <cmath>
using namespace std;

struct Node{
	int address;
	int value;
	int nextAddress;
};

int abs(int value) {
	return value >= 0 ? value : -value;
}

void printAnswer(vector<Node> list) {
	for (int i = 0; i < list.size(); ++i) {
		printf("%05d %d", list[i].address, list[i].value);
		if (i < list.size() - 1) {
			printf(" %05d\n", list[i + 1].address);
		} else {
			printf(" -1\n");
		}
	}
}

int main() {
	unordered_set<int> values;
	vector<Node> nodes(100000);
	int firstAddress;
	int n;
	scanf("%d%d", &firstAddress, &n);
	for (int i = 0; i < n; ++i) {
		Node node;
		scanf("%d%d%d", &node.address, &node.value, &node.nextAddress);
		nodes[node.address] = node;
	}
	vector<Node> remainList;
	vector<Node> removedList;
	int address = firstAddress;
	while (address != -1) {
		Node& node = nodes[address];
		if (values.count(abs(node.value)) == 0) {
			values.insert(abs(node.value));
			remainList.push_back(node);
		} else {
			removedList.push_back(node);
		}
		address = node.nextAddress;
	}

	printAnswer(remainList);
	printAnswer(removedList);
	return 0;
}