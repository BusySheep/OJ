#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while (x != 0) {
            result *= 10;
            result += x % 10;
            x /= 10;
            if (result > INT_MAX || result < INT_MIN) {
                return 0;
            }
        }
        return result;
    }
};

int main() {
    int x;
    cin >> x;
    cout << Solution().reverse(x) << endl;
	return 0;
}