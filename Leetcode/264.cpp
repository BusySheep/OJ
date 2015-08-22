#include <set>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        n--;
        int result = 1;
        set<int> uglys;
        uglys.insert(2);
        uglys.insert(3);
        uglys.insert(5);
        while (n-- && !uglys.empty()) {
            auto it = uglys.begin();
            int minUgly = *it;
            uglys.erase(it);
            result = minUgly;
            if (INT_MAX / 2 > minUgly) uglys.insert(minUgly * 2);
            if (INT_MAX / 3 > minUgly) uglys.insert(minUgly * 3);
            if (INT_MAX / 5 > minUgly) uglys.insert(minUgly * 5);
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().nthUglyNumber(n) << endl;
    return 0;
}