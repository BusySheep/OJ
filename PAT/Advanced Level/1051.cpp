#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool judge(const vector<int>& sequence, int capacity) {
	stack<int> s;
	int j = 1;
	for (int i = 0; i < sequence.size(); i++) {
		if (s.size() == 0 || sequence[i] > s.top()) {
			for ( ; j <= sequence[i]; j++) {
				s.push(j);
				if (s.size() > capacity) {
					return false;
				}
			}
			s.pop();
		}
		else if (sequence[i] == s.top()) {
			s.pop();
		}
		else {
			return false;
		}
	}
	return true;
}

int main(void) {
	int m;
	int n;
	int k;
	scanf("%d%d%d", &m, &n, &k);
	while (k--) {
		vector<int> sequence;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			sequence.push_back(x);
		}
		if (judge(sequence, m)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	system("pause");
	return 0;
}
