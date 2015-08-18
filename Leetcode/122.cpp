#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 0; i < (int)prices.size() - 1; i++) {
            int diff = prices[i + 1] - prices[i];
            if (diff > 0) {
                result += diff;
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