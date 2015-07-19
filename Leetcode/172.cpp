//
// Created by 柯瀚仰 on 15/3/29.
//
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count2;
        int count5;
        for (count2 = 0; pow(2, count2 + 1) <= n; count2++) ;
        for (count5 = 0; pow(5, count5 + 1) <= n; count5++) ;
        count2 = count2 * (count2 + 1) / 2;
        count5 = count5 * (count5 + 1) / 2;
        return min(count2, count5);
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().trailingZeroes(n);
}

