class Solution {
private:
    string add(string num1, string num2) {
        if (num1.length() == 0) return num2;
        if (num2.length() == 0) return num1;
        int carry = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result;
        int len = min(num1.length(), num2.length());
        int i = 0;
        for (; i < len; i++) {
            int temp = num1[i] - '0' + num2[i] - '0' + carry;
            carry = temp / 10;
            temp %= 10;
            result += temp + '0';
        }
        string* longer = num1.length() > num2.length() ? &num1 : &num2;
        for (; i < longer->length(); i++) {
            int temp = (*longer)[i] - '0' + carry;
            carry = temp / 10;
            temp %= 10;
            result += temp + '0';
        }
        if (carry > 0) result += carry + '0';
        reverse(result.begin(), result.end());
        return result;
    }
    string multiplySingleBit(const string& num, char bit) {
        string result;
        int carry = 0;
        for (int i = num.length() - 1; i >= 0; i--) {
            int temp = (bit - '0') * (num[i] - '0') + carry;
            carry = temp / 10;
            temp %= 10;
            result += temp + '0';
        }
        if (carry > 0) result += carry + '0';
        reverse(result.begin(), result.end());
        return result;
    }
public:
    string multiply(string num1, string num2) {
        string result;
        string carry;
        for (int i = num1.length() - 1; i >= 0; i--) {
            string temp = add(carry, multiplySingleBit(num2, num1[i]));
            result += temp.back();
            carry = temp;
            carry.pop_back();
        }
        reverse(result.begin(), result.end());
        result = carry + result;
        int i = 0;
        for (; i < result.length() - 1; i++) {
            if (result[i] != '0') break;
        }
        return result.substr(i, result.length() - i);
    }
};