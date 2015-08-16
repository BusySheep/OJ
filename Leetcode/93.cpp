#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }
        for (int i = 1; i < 4 && i < s.length() - 2; i++) {
            string a = s.substr(0, i);
            int numA = stoi(a);
            if (numA == 0 && a != "0") {
                continue;
            }
            if ((a[0] != '0' && numA < 256 && numA > 0) || (numA == 0)) {
                for (int j = i + 1; j < i + 4 && j < s.length() - 1; j++) {
                    string b = s.substr(i, j - i);
                    int numB = stoi(b);
                    if (numB == 0 && b != "0") {
                        continue;
                    }
                    if ((b[0] != '0' && numB < 256 && numB > 0) || (numB == 0)) {
                        for (int k = j + 1; k < j + 4 && k < s.length(); k++) {
                            string c = s.substr(j, k - j);
                            int numC = stoi(c);
                            if (numC == 0 && c != "0") {
                                continue;
                            }
                            if ((c[0] != '0' && numC < 256 && numC > 0) || (numC == 0)) {
                                int l = s.length();
                                string d = s.substr(k, l - k);
                                int numD = stoi(d);
                                if (numD == 0 && d != "0") {
                                    continue;
                                }
                                if (l == s.length() && ((d[0] != '0' && numD < 256 && numD > 0) || (numD == 0))) {
                                    result.push_back(a + '.' + b + '.' + c + '.' + d);
                                }
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    string s = "";
    cin >> s;
    vector<string> result = Solution().restoreIpAddresses(s);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}