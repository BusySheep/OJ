#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Student {
	int id;
	string name;
	int grade;
}students[100000];

bool compare1(Student a, Student b) {
	return a.id < b.id;
}

bool compare2(Student a, Student b) {
	if (a.name != b.name) {
		return a.name < b.name;
	} else {
		return a.id < b.id;
	}
}

bool compare3(Student a, Student b) {
	if (a.grade != b.grade) {
		return a.grade < b.grade;
	} else {
		return a.id < b.id;
	}
}

typedef bool (*Com)(Student a, Student b);
Com compares[3] = {compare1, compare2, compare3};

int main() {
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) {
		char temp[10];
		scanf("%d%s%d", &students[i].id, temp, &students[i].grade);
		students[i].name = temp;
	}
	sort(students, students + n, compares[c - 1]);
	for (int i = 0; i < n; i++) {
		printf("%06d %s %d\n", students[i].id, students[i].name.c_str(), students[i].grade);
	}
	return 0;
}