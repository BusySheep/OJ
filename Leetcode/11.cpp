#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max = 0;
        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            if (area > max) {
                max = area;
            }
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max;
    }
};
int main() {
    int n = 15000;
    // cin >> n;
    vector<int> height(n, 0);
    for (int i = 0; i < n; i++) {
        height[i] = n - i;
    }
    cout << Solution().maxArea(height) << endl;
	return 0;
}