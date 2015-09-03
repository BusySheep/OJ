#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	vector<long> s1;
	vector<long> s2;
	cin >> n;
	s1.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%ld", &s1[i]);
	}
	cin >> n;
	s2.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%ld", &s2[i]);
	}
	vector<long> s3;
	int i = 0;
	int j = 0;
	while (i < s1.size() && j < s2.size()) {
		if (s1[i] < s2[j]) {
			s3.push_back(s1[i]);
			i++;
		} else {
			s3.push_back(s2[j]);
			j++;
		}
	}
	while (i < s1.size()) {
		s3.push_back(s1[i]);
		i++;
	}
	while (j < s2.size()) {
		s3.push_back(s2[j]);
		j++;
	}
	cout << s3[(s3.size() - 1) / 2] << endl;
	return 0;
}