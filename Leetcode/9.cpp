#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long temp = 0;
        int origin = x;
        while (x != 0) {
            temp *= 10;
            temp += x % 10;
            x /= 10;
        }
        return temp == origin;
    }
};

int main() {
    int x;
    cin >> x;
    cout << Solution().isPalindrome(x) << endl;
	return 0;
}