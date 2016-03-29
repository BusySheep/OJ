#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void insertionSortStep(vector<int>& numbers, int index) {
	for (int i = 0; i < index; ++i) {
		if (numbers[i] > numbers[index]) {
			for (; i <= index; ++i) {
				swap(numbers[i], numbers[index]);
			}
			break;
		}
	}
}

void printNumbers(vector<int>& numbers) {
	for (int i = 0; i < numbers.size(); ++i) {
		if (i) putchar(' ');
		printf("%d", numbers[i]);
	}
	puts("");
}

void readNumbers(vector<int>& numbers) {
	for (int i = 0; i < numbers.size(); ++i) {
		scanf("%d", &numbers[i]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> numbers(n);
	vector<int> sequence(n);
	readNumbers(numbers);
	readNumbers(sequence);
	auto origin = numbers;

	for (int i = 0; i < n; ++i) {
		if (numbers == sequence) {
			puts("Insertion Sort");
			for (; numbers == sequence; ++i) {
				insertionSortStep(numbers, i); 
			}
			printNumbers(numbers);
			return 0;
		}
		insertionSortStep(numbers, i); // It is guaranteed that the answer is unique. So sequence must be not completely sorted.
	}

	numbers = origin;
	make_heap(numbers.begin(), numbers.end());
	for (int i = 0; i < n; ++i) {
		if (numbers == sequence) {
			puts("Heap Sort");
			for (; numbers == sequence; ++i) {
				pop_heap(numbers.begin(), numbers.end() - i);
			}
			printNumbers(numbers);
			return 0;
		}
		pop_heap(numbers.begin(), numbers.end() - i);
	}
	return 0;
}