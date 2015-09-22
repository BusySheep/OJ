class Solution {
private:
    void dfs(vector<int>& nums, vector<vector<int>>& result, int index, vector<int>& current) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        dfs(nums, result, index + 1, current);
        current.push_back(nums[index]);
        dfs(nums, result, index + 1, current);
        current.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        dfs(nums, result, 0, current);
        return result;
    }
};