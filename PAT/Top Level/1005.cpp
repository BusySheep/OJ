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

vector< pair<int, int> > hashTable(SIZE, pair<int, int>());
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

void insert(int index, int hash, int number) {
	pair<int, int>& entry = hashTable[hash];
	entry.first = index;
	entry.second += number;
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

int compareSubstring(int a, int b) {
	for (int i = 0; i < n; i++) {
    	if (s[a + i] != s[b + i]) {
      		return s[a + i] - s[b + 1];
    	}
  	}
  	return 0;
}

void printAns() {
	int maxCount = 0;
	int mostSubstring = 0;
	for (int i = 0; i < SIZE; i++) {
		if (hashTable[i].second == 0) {
			continue;
		}
		if (hashTable[i].second > maxCount) {
			maxCount = hashTable[i].second;
			mostSubstring = hashTable[i].first;
		} else if (hashTable[i].second == maxCount) {
			if (compareSubstring(mostSubstring, hashTable[i].first) > 0) {
				mostSubstring = hashTable[i].first;
			}
		}
	}
	printf("%s %d\n", s.substr(mostSubstring, n).c_str(), maxCount);
}

int main() {
	scanf("%d", &n);
	getchar();
	char temp[1048578];
	gets(temp);
	s = temp;

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