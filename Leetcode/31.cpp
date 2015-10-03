class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for (i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) break;
        }
        reverse(nums.begin() + i + 1, nums.end());
        if (i < 0) return;
        int position = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]) - nums.begin();
        int temp = nums[position];
        nums[position] = nums[i];
        nums[i] = temp;
    }
};