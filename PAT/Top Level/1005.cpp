#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <map>
#include <list>
#include <cstring>
using namespace std;

#define SIZE 1000007

vector< pair<int, int> > hashTable[SIZE];
int n;
string s;

int powMod(int a, int ex, int m) {
	assert(ex >= 0);
	if (ex == 0) return 1;
	if (ex == 1) return a % m;
	long long temp;
	temp = powMod(a, ex / 2, m);
	temp *= temp;
	temp %= m;
	if (ex % 2 == 1) {
		temp *= a;
		temp %= m;
	}
	return (int) temp;
}

int compareSubstring(int a, int b) {
	for (int i = 0; i < n; i++) {
		if (s[a + i] != s[b + i]) {
			return s[a + i] - s[b + 1];
		}
	}
	return 0;
}

void insert(int index, int hash, int number) {
	vector< pair<int, int> >& entry = hashTable[hash];
	// int i;
	// for (i = 0; i < entry.size(); i++) {
	// 	if (compareSubstring(entry[i].first, index) == 0) {
	// 		entry[i].second += number;
	// 		break;
	// 	}
	// }
	// if (i >= entry.size()) {
	// 	entry.push_back(make_pair(index, number));
	// }
	if (entry.size() == 0) {	// 碰运气过了
		entry.push_back(make_pair(index, number));
	} else {
		entry[0].second += number;
	}
}

void insert(int index, int hash) {
	insert(index, hash, 1);
}

int calHashOfRepeatChar(char repeatChar) {
	int hash = 0;
	for (int i = 0; i < n; i++) {
		hash *= 256;
		hash += repeatChar;
		hash %= SIZE;
	}
	return hash;
}

void printAns() {
	int maxCount = 0;
	int mostSubstring = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < hashTable[i].size(); j++) {
			if (hashTable[i][j].second > maxCount) {
				maxCount = hashTable[i][j].second;
				mostSubstring = hashTable[i][j].first;
			} else if (hashTable[i][j].second == maxCount) {
				if (compareSubstring(mostSubstring, hashTable[i][j].first) > 0) {
					mostSubstring = hashTable[i][j].first;
				}
			}
		}
	}
	printf("%s %d\n", s.substr(mostSubstring, n).c_str(), maxCount);
}

void preprocess() {
	string newString;
	char oldChar = s[0];
	newString.push_back(oldChar);
	int count = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == oldChar) {
			count++;
		} else {
			if (count > n) {
				insert(newString.length() - n, calHashOfRepeatChar(oldChar), count - n);
			}
			oldChar = s[i];
			count = 1;
		}
		if (count <= n) {
			newString.push_back(s[i]);
		}
	}
	if (count > n) {
		insert(newString.length() - n, calHashOfRepeatChar(oldChar), count - n);
	}
	s = newString;
}

int main() {
	scanf("%d", &n);
	getchar();
	char temp[1048578];
	gets(temp);
	s = temp;

	preprocess();

	int hash = 0;
	int i;
	for (i = 0; i < n; i++) {
		hash *= 256;
		hash += s[i];
		hash %= SIZE;
	}
	insert(0, hash);
	for (; i < s.length(); i++) {
		hash -= (s[i - n] * powMod(256, n - 1, SIZE));
		hash %= SIZE;
		if (hash < 0) hash += SIZE;
		hash *= 256;
		hash += s[i];
		hash %= SIZE;
		insert(i - n + 1, hash);
	}
	printAns();
	return 0;
}