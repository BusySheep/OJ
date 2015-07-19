#include <cstdio>
#include <string>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j;
        set<char> substring;
        int result = 0;
        for (i = 0, j = 0; j < s.length(); ) {
            if (substring.count(s[j]) == 0) {
                substring.insert(s[j]);
                j++;
                result = max(result, (int)substring.size());
            } else {
                substring.erase(s[i]);
                i++;
            }
        }
        return result;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().lengthOfLongestSubstring(s);
    return 0;
}