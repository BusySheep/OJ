#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int maxPrice = INT_MIN;
        int result = 0;
        for (int i = prices.size() - 1; i >= 0; i--) {
            maxPrice = max(prices[i], maxPrice);
            if (maxPrice - prices[i] > result) {
                result = maxPrice - prices[i];
            }
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> prices(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}