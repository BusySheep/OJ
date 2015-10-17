class Solution {
private:
    int find(const string& s, char c) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) return i;
        }
        return -1;
    }
    void trim(string& s) {
        int begin = 0;
        while (s[begin] == ' ') begin++;
        int end = s.length() - 1;
        while (s[end] == ' ') end--;
        s = s.substr(begin, end - begin + 1);
    }
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    bool isInteger(string s, bool defaultAnswer = false) {
        if (s.length() == 0) return defaultAnswer;
        for (int i = 0; i < s.length(); i++) {
            if (!isDigit(s[i])) return false;
        }
        return true;
    }
    bool isSign(char c) {
        return c == '+' || c == '-';
    }
    bool isReal(string s, bool defaultAnswer = false) {
        if (s.length() == 0) return defaultAnswer;
        int pointPosition = find(s, '.');
        if (pointPosition != -1) {
            string left = s.substr(0, pointPosition);
            string right = s.substr(pointPosition + 1, s.length() - (pointPosition + 1));
            if (left == "" && right == "") return false;
            return isInteger(left, true) && isInteger(right, true);
        } else {
            return isInteger(s);
        }
    }
public:
    bool isNumber(string s) {
        trim(s);
        if (s.length() > 0 && isSign(s[0])) s.erase(s.begin());
        int ePosition = find(s, 'e');
        if (ePosition != -1) {
            string left = s.substr(0, ePosition);
            string right = s.substr(ePosition + 1, s.length() - (ePosition + 1));
            if (right.length() > 0 && isSign(right[0])) right.erase(right.begin());
            return isReal(left) && isInteger(right);
        } else {
            return isReal(s);
        }
    }
};