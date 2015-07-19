#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <functional>
using namespace std;

multiset<int> upper;
multiset<int, greater<int>> lower;
vector<int> stack;

void maintain() {
	if (stack.size() % 2 == 1 && upper.size() > lower.size() + 1 || stack.size() % 2 == 0 && upper.size() > lower.size()) {
		lower.insert(*upper.begin());
		upper.erase(upper.begin());
	}
	else if (stack.size() % 2 == 1 && upper.size() < lower.size() + 1 || stack.size() % 2 == 0 && upper.size() < lower.size()) {
		upper.insert(*lower.begin());
		lower.erase(lower.begin());
	}
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		char command[20];
		scanf("%s", command);
		getchar();
		if (command[1] == 'u') {
			int x;
			scanf("%d", &x);
			getchar();
			stack.push_back(x);
			if (upper.size() == 0 || x >= *upper.begin()) {
				upper.insert(x);
			}
			else {
				lower.insert(x);
			}

			maintain();
		}
		else if (command[1] == 'o') {
			if (stack.size() > 0) {
				int x = stack[stack.size() - 1];
				stack.pop_back();
				printf("%d\n", x);
				if (x >= *upper.begin()) {
					upper.erase(upper.find(x));
				}
				else {
					lower.erase(lower.find(x));
				}
				maintain();
			}
			else {
				printf("Invalid\n");
			}
		}
		else if (command[1] == 'e') {
			if (stack.size() > 0) {
				int mid;
				if (stack.size() % 2 == 1) {
					mid = *upper.begin();
				}
				else {
					mid = *lower.begin();
				}
				printf("%d\n", mid);
			}
			else {
				printf("Invalid\n");
			}
		}
	}
	system("pause");
	return 0;
}

