#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	getchar();
	vector<map<string, set<int>>> record;
	record.resize(5);
	map<string, set<int>>& title = record[0];
	map<string, set<int>>& author = record[1];
	map<string, set<int>>& keyword = record[2];
	map<string, set<int>>& publisher = record[3];
	map<string, set<int>>& publishedYear = record[4];
	for (int i = 0; i < n; i++) {
		int id;
		scanf("%d", &id);
		getchar();
		char temp[81];
		gets(temp);
		title[temp].insert(id);
		gets(temp);
		author[temp].insert(id);

		//key words
		gets(temp);
		char tempWord[11];
		int index = 0;
		for (int j = 0; temp[j]; j++) {
			if (temp[j] == ' ') {
				tempWord[index] = 0;
				keyword[tempWord].insert(id);
				index = 0;
			}
			else {
				tempWord[index++] = temp[j];
			}
		}
		tempWord[index] = 0;
		keyword[tempWord].insert(id);

		gets(temp);
		publisher[temp].insert(id);
		gets(temp);
		publishedYear[temp].insert(id);
	}
	int m;
	scanf("%d", &m);
	getchar();
	for (int i = 0; i < m; i++) {
		char temp[100];
		gets(temp);
		string query = temp + 3;
		int choice = temp[0] - '1';
		puts(temp);
		if (record[choice].count(query) == 0) {
			printf("Not Found\n");
		}
		else {
			set<int> result = record[choice][query];
			for (auto it = result.begin(); it != result.end(); it++) {
				printf("%07d\n", *it);
			}
		}
	}
	system("pause");
	return 0;
}
