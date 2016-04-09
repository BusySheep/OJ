#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char const* operations[6] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};

struct State {
	int operation = 0;
	pair<int, int> lastState = make_pair(-1, -1);
	State() {}
	State(int o, pair<int, int> l) : operation(o), lastState(l) {}
};

void solve(int ca, int cb, int n) {
	vector<vector<State *>> states(1001, vector<State *>(1001, nullptr));
	queue<pair<int, int>> q;
	states[0][0] = new State;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		auto currentState = q.front();
		q.pop();
		int a = currentState.first;
		int b = currentState.second;

		if (b == n) {
			// print answer
			vector<int> answer;
			while (!(a == 0 && b == 0)) {
				answer.push_back(states[a][b]->operation);
				auto lastState = states[a][b]->lastState;
				a = lastState.first;
				b = lastState.second;
			}
			for (int i = answer.size() - 1; i >= 0; --i) {
				puts(operations[answer[i]]);
			}
			puts("success");
			return;
		}

		int additionA[6] = {ca - a, 0, -a, 0, -min(a, cb - b), min(b, ca - a)};
		int additionB[6] = {0, cb - b, 0, -b, min(a, cb - b), -min(b, ca - a)};
		for (int i = 0; i < 6; ++i) {
			auto newState = make_pair(a + additionA[i], b + additionB[i]);
			if (states[newState.first][newState.second] == nullptr) {
				states[newState.first][newState.second] = new State(i, currentState);
				q.push(newState);
			}
		}
	}
	for (int i = 0; i <= ca; ++i) {
		for (int j = 0; j <= cb; ++j) {
			if (states[i][j] != nullptr) {
				delete states[i][j];
			}
		}
	}
}

int main() {
	int ca;
	int cb;
	int n;
	while (scanf("%d%d%d", &ca, &cb, &n) != -1) {
		solve(ca, cb, n);
	}
	return 0;
}