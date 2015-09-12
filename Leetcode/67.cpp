#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "" && b == "") return "0";
        if (a.length() < b.length()) {
            string temp = a;
            a = b;
            b = temp;
        }
        int lenDiff = a.length() - b.length();
        string temp(lenDiff, '0');
        b = temp + b;
        int carry = 0;
        for (int i = a.length() - 1; i >= 0; i--) {
            int temp = (a[i] - '0') + (b[i] - '0') + carry;
            carry = temp / 2;
            temp &= 1;
            a[i] = temp + '0';
        }
        if (carry == 1) {
            a.insert(a.begin(), '1');
        }
        return a;
    }
};

int main() {
    string a, b;
    cin >> a >> b;
    cout << Solution().addBinary(a, b) << endl;
    return 0;
}