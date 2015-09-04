class Solution {
private:
    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    char lowercase(char c) {
        if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
        else return c;
    }
public:
    bool isPalindrome(string s) {
        string str;
        for (int i = 0; i < s.length(); i++) {
            s[i] = lowercase(s[i]);
            if (isAlphanumeric(s[i])) {
                str.push_back(s[i]);
            }
        }
        for (int i = 0; i < str.length() / 2; i++) {
            if (str[i] != str[str.length() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};