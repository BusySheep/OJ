#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string trim(string str) {
        for (int i = str.length() - 1; i >= 0; i--) {
            if (str[i] == ' ') {
                str.pop_back();
            } else {
                break;
            }
        }
        int i;
        for (i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                break;
            }
        }
        return str.substr(i, str.length() - i);
    }
    int myAtoi(string str) {
        str = trim(str);
        if (str == "") {
            return 0;
        }
        int result = 0;
        bool negativeFlag = false;
        bool signFlag = false;
        bool numberFlag = false;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '-' || str[i] == '+') {
                if (signFlag == true) {
                    return 0;
                } else if (numberFlag == true) {
                    return result;
                }
                signFlag = true;
                if (str[i] == '-') {
                    negativeFlag = true;
                }
            } else if (str[i] <= '9' && str[i] >= '0') {
                numberFlag = true;
                if (negativeFlag) {
                    if ((INT_MIN + (str[i] - '0')) / 10 > result) {
                        return INT_MIN;
                    }
                    result = result * 10 - (str[i] - '0');
                } else {
                    if ((INT_MAX - (str[i] - '0')) / 10 < result) {
                        return INT_MAX;
                    }
                    result = result * 10 + (str[i] - '0');
                }
            } else {
                return result;
            }
        }
        return result;
    }
};

int main() {
    string str;
    cin >> str;
    cout << Solution().myAtoi(str) << endl;
	return 0;
}