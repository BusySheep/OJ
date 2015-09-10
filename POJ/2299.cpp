#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;

long long solve(int begin, int end) {
	if (begin >= end - 1) return 0;
	int mid = (begin + end) / 2;
	long long ans = 0;
	ans += solve(begin, mid);
	ans += solve(mid, end);
	vector<int> temp(end - begin, 0);
	int i = begin;
	int j = mid;
	int count = 0;
	while (i < mid && j < end) {
		if (numbers[i] <= numbers[j]) {
			temp[count++] = numbers[i++];
		} else {
			ans += mid - i;
			temp[count++] = numbers[j++];
		}
	}
	while (i < mid) {
		temp[count++] = numbers[i++];
	}
	while (j < end) {
		temp[count++] = numbers[j++];
	}
	for (int k = 0; k < temp.size(); k++) {
		numbers[begin + k] = temp[k];
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n) {
		numbers.assign(n, 0);
		for (int i = 0; i < n; i++) {
			scanf("%d", &numbers[i]);
		}
		long long ans = solve(0, n);
		printf("%lld\n", ans);
		scanf("%d", &n);
	}
	return 0;
}