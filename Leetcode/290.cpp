class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> patternToStr;
        unordered_map<string, char> strToPattern;
        string current;
        int j = 0;
        for (int i = 0; i <= str.length(); i++) {
            if (j == pattern.length()) return false;
            if (i < str.length() && str[i] != ' ') {
                current += str[i];
            } else {
                if (patternToStr.count(pattern[j]) != 0) {
                    if (current != patternToStr[pattern[j]]) return false;
                } else if (strToPattern.count(current) != 0) {
                    if (strToPattern[current] != pattern[j]) return false;
                } else {
                    patternToStr[pattern[j]] = current;
                    strToPattern[current] = pattern[j];
                }
                j++;
                current.clear();
            }
        }
        if (j == pattern.length()) return true;
        else return false;
    }
};