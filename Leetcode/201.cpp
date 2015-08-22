#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = m;
        int step = 1;
        if (result == 0) {
            return result;
        }
        while ((result & step) == 0) {
            step <<= 1;
        }
        for (int i = m + step; i <= n; ) {
            if (i < 0) {
                return result;
            }
            result &= i;
            if (result == 0) {
                return result;
            }
            while ((result & step) == 0) {
                step <<= 1;
            }
            i += step;
            i -= i % step;
        }
        return result;
    }
};

int main() {
    int m;
    int n;
    cin >> m >> n;
    cout << Solution().rangeBitwiseAnd(m, n) << endl;
    return 0;
}
