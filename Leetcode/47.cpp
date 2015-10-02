class Solution {
private:
    unordered_map<int, int> rest;
    vector<vector<int>> result;
    vector<int> current;
    void solve(vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        for (auto it = rest.begin(); it != rest.end(); it++) {
            if (it->second > 0) {
                it->second--;
                current.push_back(it->first);
                solve(nums, index + 1);
                current.pop_back();
                it->second++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        current.clear();
        for (int i = 0; i < nums.size(); i++) {
            rest[nums[i]]++;
        }
        solve(nums, 0);
        return result;
    }
};