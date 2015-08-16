#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int index = 1; index < n; index++) {
            int i = 0;
            stringstream ss;
            while (i < result.length()) {
                int count = 1;
                while (i + count < result.length() && result[i + count] == result[i]) {
                    count++;
                }
                ss << count << result[i];
                i += count;
            }
            result = ss.str();
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().countAndSay(n) << endl;
    return 0;
}