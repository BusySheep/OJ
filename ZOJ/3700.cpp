#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        getchar();
        map<string, int> wordCount;
        while (n--) {
            char line[110];
            gets(line);
            char temp[110];
            int count = 0;
            for (int i = 0; ; i++) {
                if (line[i] >= 'a' && line[i] <= 'z') {
                    temp[count++] = line[i];
                }
                else if (line[i] >= 'A' && line[i] <= 'Z') {
                    temp[count++] = line[i] - 'A' + 'a';
                }
                else if (line[i] == 0) {
                    temp[count] = 0;
                    if (count != 0) {
                        wordCount[temp]++;
                    }
                    count = 0;
                    break;
                }
                else {
                    temp[count] = 0;
                    if (count != 0) {
                        wordCount[temp]++;
                    }
                    count = 0;
                }
            }
        }
        map<int, set<string> > groups;
        for (auto it = wordCount.begin(); it != wordCount.end(); it++) {
            groups[it->second].insert(it->first);
        }
        bool headFlag = true;
        for (auto it = groups.rbegin(); it != groups.rend(); it++) {
            if (it->first > 1) {
                set<string> temp;
                int maxLength = 0;
                for (auto strIt = it->second.begin(); strIt != it->second.end(); strIt++) {
                    if (strIt->size() > maxLength) {
                        temp.clear();
                        temp.insert(*strIt);
                        maxLength = (int)strIt->size();
                    }
                    else if (strIt->size() == maxLength) {
                        temp.insert(*strIt);
                    }
                }
                auto strIt = temp.rbegin();
                string result = *strIt;
                strIt++;
                if (strIt != temp.rend()) {
                    result = *strIt;
                }
                if (!headFlag) {
                    putchar(' ');
                }
                else {
                    headFlag = false;
                }
                printf("%s", result.c_str());
            }
        }
        putchar('\n');
    }
    return 0;
    
}

