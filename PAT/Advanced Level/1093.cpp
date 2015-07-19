#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    string pattern = "PAT";
    vector<int> cnt(str.size(), 1);
    for (int i = 0; i < pattern.size(); i++) {
        int count = 0;
        for (auto j = 0; j < str.size(); j++) {
            if (str[j] == pattern[i]) {
                count += cnt[j];
                count %= 1000000007;
            }
            cnt[j] = count;
        }
    }
    if (str.size() == 0) {
        printf("0\n");
    }
    else {
        printf("%d\n", cnt[str.size() - 1]);
    }
    return 0;
}
