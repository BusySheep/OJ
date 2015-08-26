#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<long> sequence;
vector<long> partially;

vector<long> insertionSort(void) {
	vector<long> seq = sequence;
	bool flag = false;
	for (int i = 0; i < seq.size(); i++) {
		int j;
		for (j = 0; j < i; j++) {
			if (seq[j] > seq[i]) {
				break;
			}
		}
		int position = j;
		long number = seq[i];
		seq.erase(seq.begin() + i);
		seq.insert(seq.begin() + position, number);
		if (flag && seq != partially) {//如果出现多次迭代序列并未发生变化的情况，认为partially是最后一次迭代
			return seq;
		}
		if (seq == partially) {
			flag = true;
		}
	}
	return vector<long>();
}

void merge(int begin, int mid, int end, vector<long>& seq) {
	int i = begin;
	int j = mid;
	vector<long> temp;
	for (; i < mid || j < end;) {
		if (i < mid && j < end) {
			if (seq[i] < seq[j]) {
				temp.push_back(seq[i]);
				i++;
			}
			else {
				temp.push_back(seq[j]);
				j++;
			}
		}
		else if (i < mid) {
			temp.push_back(seq[i]);
			i++;
		}
		else if (j < end) {
			temp.push_back(seq[j]);
			j++;
		}
	}
	for (int k = begin; k < end; k++) {
		seq[k] = temp[k - begin];
	}
}

vector<long> mergeSort(void) {
	vector<long> seq = sequence;
	bool flag = false;
	for (int i = 0; pow(2, i) < seq.size(); i++) {
		int range = pow(2, i);
		for (int j = 0; j + range < seq.size(); j += 2 * range) {
			merge(j, j + range, min(j + 2 * range, (int)seq.size()), seq);
		}
		if (flag && seq != partially) {
			return seq;
		}
		if (seq == partially) {
			flag = true;
		}
	}
	return vector<long>();
}

int main(void) {
	int n;
	scanf("%d", &n);
	sequence.resize(n);
	partially.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%ld", &sequence[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%ld", &partially[i]);
	}
	vector<long> next = mergeSort();
	if (next.size() != 0) {
		puts("Merge Sort");
	}
	else {
		next = insertionSort();
		puts("Insertion Sort");
	}
	for (int i = 0; i < next.size(); i++) {
		if (i) {
			putchar(' ');
		}
		printf("%ld", next[i]);
	}
	puts("");
	system("pause");
	return 0;
}
