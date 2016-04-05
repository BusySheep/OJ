#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

char word[82];
char line[81];
int pos = 0;

void outputLine(char * line) {
	puts(line);
	pos = 0;
	line[0] = 0;
}

int main() {
	while (scanf("%s", word) != -1) {
		if (strcmp(word, "<br>") == 0) {
			outputLine(line);
		} else if (strcmp(word, "<hr>") == 0) {
			if (pos > 0) {
				outputLine(line);
			}
			puts("--------------------------------------------------------------------------------");
		} else {
			int len = strlen(word);
			if ((pos == 0 && len > 80) || (pos > 0 && len + pos + 1 > 80)) {
				outputLine(line);
			} else if (pos > 0) {
				line[pos++] = ' ';
				line[pos] = 0;
			}
			strcpy(line + pos, word);
			pos += len;
		}
	}
	if (pos > 0) {
		puts(line);
	}
	return 0;
}