class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return binary_search(nums.begin(), nums.end(), target) ? (vector<int>{  
            lower_bound(nums.begin(), nums.end(), target) - nums.begin(), 
            upper_bound(nums.begin(), nums.end(), target) - 1 - nums.begin()
        }) : (vector<int>{-1, -1});
    }
};