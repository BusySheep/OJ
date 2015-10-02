class Solution {
private:
    void solve(vector<int>& nums, int index, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                current.push_back(nums[i]);
                solve(nums, index + 1, current, used, result);
                current.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> current;
        solve(nums, 0, current, used, result);
        return result;
    }
};