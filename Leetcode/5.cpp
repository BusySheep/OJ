#include <cstdio>
#include <string>
#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        pair<int, int> longestSubstringIndex = make_pair(0, 0);
        bool dp[1000][1000];
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
        }
        for (int i = 1; i < s.length(); i++) {
            dp[i][i - 1] = true;
        }
        for (int i = (int)s.length() - 2; i >= 0; i--) {
            for (int j = i + 1; j < s.length(); j++) {
                dp[i][j] = (dp[i + 1][j - 1] == true && s[i] == s[j]);
                if (dp[i][j] == true && j - i > longestSubstringIndex.second - longestSubstringIndex.first) {
                    longestSubstringIndex.first = i;
                    longestSubstringIndex.second = j;
                }
            }
        }
        return s.substr(longestSubstringIndex.first, longestSubstringIndex.second - longestSubstringIndex.first + 1);
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().longestPalindrome(s);
    return 0;
}