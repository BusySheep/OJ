#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector< pair<int, int> > numbers(nums.size(), pair<int, int>());
        for (int i = 0; i < nums.size(); i++) {
            numbers[i].first = nums[i];
            numbers[i].second = i;
        }
        sort(numbers.begin(), numbers.end());
        int i;
        int j;
        vector<int> result;
        for (i = 0, j = (int)numbers.size() - 1; i < j; ) {
            if (numbers[i].first + numbers[j].first == target) {
                result.push_back(min(numbers[i].second + 1, numbers[j].second + 1));
                result.push_back(max(numbers[i].second + 1, numbers[j].second + 1));
                return result;
            } else if (numbers[i].first + numbers[j].first < target) {
                i++;
            } else {
                j--;
            }
        }
        return result;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    int target;
    scanf("%d", &target);
    vector<int> input(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    vector<int> result = Solution().twoSum(input, target);
    printf("index1 = %d, index2 = %d\n", result[0], result[1]);
    return 0;
}