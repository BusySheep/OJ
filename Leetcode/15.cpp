class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] == -nums[i]) {
                    result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    int temp = nums[j];
                    while (j < k && nums[++j] == temp) ;
                    temp = nums[k];
                    while (j < k && nums[--k] == temp) ;
                } else if (nums[j] + nums[k] < -nums[i]) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return result;
    }
};