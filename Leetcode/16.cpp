class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = target + INT_MAX;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                sum = nums[j] + nums[k] + nums[i];
                if (abs(sum - target) < abs(result - target)) result = sum;
                if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return result;
    }
};