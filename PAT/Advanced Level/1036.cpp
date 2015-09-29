#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	bool isMale;
	string id;
	int grade;
	bool operator<(Student another) {
		return grade < another.grade;
	}
	void input() {
		string gender;
		cin >> name >> gender >> id >> grade;
		isMale = gender == "M";
	}
};

int main() {
	int n;
	cin >> n;
	Student lowestMaleStudent;
	Student highestFemaleStudent;
	lowestMaleStudent.grade = 101;
	highestFemaleStudent.grade = -1;
	for (int i = 0; i < n; i++) {
		Student temp;
		temp.input();
		if (temp.isMale && temp < lowestMaleStudent) {
			lowestMaleStudent = temp;
		} else if (!temp.isMale && highestFemaleStudent < temp) {
			highestFemaleStudent = temp;
		}
	}
	bool absentFlag = false;
	if (highestFemaleStudent.id == "") {
		absentFlag = true;
		cout << "Absent" << endl;
	} else {
		cout << highestFemaleStudent.name + " " + highestFemaleStudent.id << endl;
	}
	if (lowestMaleStudent.id == "") {
		absentFlag = true;
		cout << "Absent" << endl;
	} else {
		cout << lowestMaleStudent.name + " " + lowestMaleStudent.id << endl;
	}
	if (absentFlag) {
		cout << "NA" << endl;
	} else {
		cout << highestFemaleStudent.grade - lowestMaleStudent.grade << endl;
	}
	return 0;
}