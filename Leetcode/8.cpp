class Solution {
private:
    string trim(string s) {
        int begin = 0;
        while (s[begin] == ' ') begin++;
        int end = s.length() - 1;
        while (s[end] == ' ') end--;
        return s.substr(begin, end + 1 - begin);
    }
    int charToInt(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        else return -1;
    }
    int genResult(long result, int sign) {
        result *= sign;
        if (result > INT_MAX) return INT_MAX;
        else if (result < INT_MIN) return INT_MIN;
        else return result;
    }
public:
    int myAtoi(string str) {
        str = trim(str);
        int sign = 1;
        int i = 0;
        if (str[0] == '-') {
            sign = -1;
            i++;
        } else if (str[0] == '+') {
            i++;
        }
        long result = 0;
        for (; i < str.length(); i++) {
            int temp = charToInt(str[i]);
            if (temp == -1) return genResult(result, sign);
            result *= 10;
            result += temp;
            if (result > 10000000000L) return genResult(result, sign);
        }
        return genResult(result, sign);
    }
};